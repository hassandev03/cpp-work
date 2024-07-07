#include <iostream>
#include <math.h>
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
int evaluatePostfix(string str)
{
    Stack s;
    for (int i = 0; i < str.size(); i++)
    {
        if (('0' <= str[i] && str[i] <= '9'))
            s.push(str[i] - '0');
        else
        {
            int second = s.pop();
            int first = s.pop();
            switch (str[i])
            {
            case '^':
            {
                s.push(pow(first, second));
                break;
            }
            case '/':
            {
                s.push(first / second);
                break;
            }
            case '*':
            {
                s.push(first * second);
                break;
            }
            case '-':
            {
                s.push(first - second);
                break;
            }
            case '+':
            {
                s.push(first + second);
                break;
            }
            default:
                break;
            }
        }
    }
    return s.pop();
}

int main()
{
    cout << evaluatePostfix("723-*54+/");
    return 0;
}