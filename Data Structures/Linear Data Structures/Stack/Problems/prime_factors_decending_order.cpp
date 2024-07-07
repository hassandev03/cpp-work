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
            // cout << "--- Stack ---\n";
            Node *temp = top;
            while (temp != nullptr)
            {
                if (temp->link == nullptr)
                    cout << temp->data << endl;
                else
                    cout << temp->data << ", ";
                temp = temp->link;
            }
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

void displayPrimeFactors(int num)
{
    if (num < 0)
    {
        cout << "Negative Integer!" << endl;
        return;
    }
    else if (num == 0 || num == 1)
    {
        cout << "No prime number exists for this number!" << endl;
        return;
    }
    int div = 2;
    Stack *myStack = new Stack;
    while (num != 1)
    {
        while (num % div == 0)
        {
            num /= div;
            myStack->push(div);
        }
        div++;
    }

    cout << "Prime Factors of " << num << "are: ";
    myStack->display();
    // myStack->deleteStack();
}

int main()
{
    displayPrimeFactors(450);
    return 0;
}