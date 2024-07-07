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
    Node *top = nullptr, *tail = nullptr;

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

    void display()
    {
        if (isEmpty())
            displayStackUnderFlowMessage();
        else
        {
            // cout << "--- Stack ---\n";
            Node *temp = top;
            while (temp != nullptr)
            {
                cout << temp->data;
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

void decimalToBinary(int num)
{
    int origNum = num;
    if (num < 0)
    {
        cout << "Negative Integer!" << endl;
        return;
    }

    Stack *myStack = new Stack;
    do
    {
        myStack->push(num % 2);
        num /= 2;

    } while (num != 0);

    cout << origNum << " to Binary is: ";
    myStack->display();
}

int main()
{
    decimalToBinary(10);
    return 0;
}