#include <iostream>
#include <stack>

using namespace std;

bool isOpenParenthesis(char ch, char opening[]) {
    for (int i = 0; i < 3; i++) {
        if (ch == opening[i]) {
            return true;
        }
    }
    return false;
}

bool isCloseParenthesis(char ch, char closing[]) {
    for (int i = 0; i < 3; i++) {
        if (ch == closing[i]) {
            return true;
        }
    }
    return false;
}

bool matches(char open, char close, char opening[], char closing[]) {
    for (int i = 0; i < 3; i++) {
        if (open == opening[i] && close == closing[i]) {
            return true;
        }
    }
    return false;
}

bool isBalanced(string expr) {
    stack<char> stack;
    char opening[] = {'(', '{', '['};
    char closing[] = {')', '}', ']'};

    for (char ch : expr) {
        if (isOpenParenthesis(ch, opening)) {
            stack.push(ch);
        } else if (isCloseParenthesis(ch, closing)) {
            if (stack.empty() || !matches(stack.top(), ch, opening, closing)) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}

int main() {
    string expr1 = "[{()}]"; // Balanced
    string expr2 = "({})";   // Unbalanced
    string expr3 = "{([])}"; // Unbalanced

    cout << "Expression 1 is balanced: " << boolalpha << isBalanced(expr1) << endl;
    cout << "Expression 2 is balanced: " << boolalpha << isBalanced(expr2) << endl;
    cout << "Expression 3 is balanced: " << boolalpha << isBalanced(expr3) << endl;

    return 0;
}
