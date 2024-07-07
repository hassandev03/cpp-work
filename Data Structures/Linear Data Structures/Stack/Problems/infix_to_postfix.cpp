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
string infixToPostfix(string str)
{
    Stack *s = new Stack;
    string postfixExp = "";
    for (int i = 0; i < str.size(); i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
            postfixExp += str[i];
        else
        {
            switch (str[i])
            {
            case '(':
            {
                s->push(str[i]);
                break;
            }
            case ')':
            {
                while (!s->isEmpty() && s->peek() != '(')
                    postfixExp += s->pop();
                // pop the '('
                if (!s->isEmpty())
                    s->pop();
                break;
            }
            case '^':
            case '/':
            case '*':
            case '-':
            case '+':
            {
                while (!s->isEmpty() && getPrecedence(s->peek()) >= getPrecedence(str[i]))
                    postfixExp += s->pop();
                // after removing all higher and equal precendence operators
                s->push(str[i]);
                break;
            }
            default:
                break;
            }
        }
    }
    // now add append all the remaining elements to string
    while (!s->isEmpty())
        postfixExp += s->pop();
    delete s;
    return postfixExp;
}

int main()
{
    cout << infixToPostfix("7 + 9 * (8 + 6 / 3) - 2") << endl;
    return 0;
}