#include <iostream>
using namespace ::std;

class Stack
{
private:
    struct Node
    {
        int data;
        Node *link = nullptr;
    };
    Node *top = nullptr;

    void displayStackUnderFlowMessage()
    {
        cout << "Stack UnderFlow!" << endl;
    }

public:
    Stack()
    {
    }

    Stack(int data)
    {
        push(data);
    }

    bool isEmpty()
    {
        if (top == nullptr)
            return true;
        return false;
    }

    int getSize()
    {
        if (isEmpty())
            displayStackUnderFlowMessage();
        else
        {
            Node *temp = top;
            int count = 0;
            while (temp != nullptr)
            {
                ++count;
                temp = temp->link;
            }
            return count;
        }
    }

    void display()
    {
        if (isEmpty())
            displayStackUnderFlowMessage();
        else
        {
            cout << "--- Stack ---\n";
            Node *temp = top;
            while (temp != nullptr)
            {
                cout << "    " << temp->data << endl;
                temp = temp->link;
            }
            cout << endl;
        }
    }

    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        if (isEmpty())
            top = newNode;
        else
        {
            newNode->link = top;
            top = newNode;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            displayStackUnderFlowMessage();
            exit(1);
        }
        else
        {
            Node *temp = top;
            int poppedValue = temp->data;
            top = top->link;
            delete temp;
            temp = nullptr;
            return poppedValue;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            displayStackUnderFlowMessage();
            return 0;
        }
        else
            return top->data;
    }

    void deleteStack()
    {
        if (isEmpty())
            displayStackUnderFlowMessage();
        else
        {
            Node *next = top;
            while (next != nullptr)
            {
                pop();
                next = next->link;
            }
        }
    }
};

int getPrecedence(char ch)
{
    switch (ch)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

string reverse(string str)
{
    int low = 0, high = str.size() - 1;
    while (low < high)
    {
        char ch = str[low];
        str[low] = str[high];
        str[high] = ch;
        low++;
        high--;
    }
    return str;
}

char getOppositeBracket(char ch)
{
    switch (ch)
    {
    case '[':
        return ']';
    case '{':
        return '}';
    case '(':
        return ')';
    case '<':
        return '>';
    case ']':
        return '[';
    case '}':
        return '{';
    case ')':
        return '(';
    case '>':
        return '<';
    default:
        return '.';
    }
}

string changeBrackets(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(' || str[i] == '<')
            str[i] = getOppositeBracket(str[i]);
        else if (str[i] == ']' || str[i] == '}' || str[i] == ')' || str[i] == '>')
            str[i] = getOppositeBracket(str[i]);
    }
    return str;
}

string infixToPrefix(string str)
{
    str = reverse(str);
    str = changeBrackets(str);
    string prefixStr = "";
    Stack s;
    for (int i = 0; i < str.size(); i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
            prefixStr += str[i];
        else
        {
            switch (str[i])
            {
            case '(':
            {
                s.push(str[i]);
                break;
            }
            case ')':
            {
                while (!s.isEmpty() && s.peek() != '(')
                    prefixStr += s.pop();
                // pop the '('
                if (!s.isEmpty())
                    s.pop();
                break;
            }
            case '^':
            case '/':
            case '*':
            case '-':
            case '+':
            {
                while (!s.isEmpty() && getPrecedence(s.peek()) >= getPrecedence(str[i]))
                    prefixStr += s.pop();
                // after removing all higher and equal precendence operators
                s.push(str[i]);
                break;
            }
            default:
                break;
            }
        }
    }
    // now add append all the remaining elements to string
    while (!s.isEmpty())
        prefixStr += s.pop();
    return reverse(prefixStr);
}

int main()
{
    cout << infixToPrefix("(9 - 6 / 2) * (9 / 5 - 3)");
    return 0;
}