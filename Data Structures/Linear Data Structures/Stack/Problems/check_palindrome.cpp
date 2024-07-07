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
};

bool isPalindrome(string str, char midChar)
{
    int i = 0;
    Stack *myStack = new Stack;
    do
    {
        myStack->push(str[i]);
        i++;
    } while (str[i] != midChar);
    // skip special character
    i++;
    do
    {
        if (str[i] != myStack->pop())
            return false;
        i++;
    } while (!myStack->isEmpty());
    return true;
}

int main()
{
    // always give string with a marked special character which will mark the middle of string
    // in our case it will be &
    cout << "Is \"das&sad\" palindrome? " << isPalindrome("dasd&sadd", '&') << endl;
    return 0;
}