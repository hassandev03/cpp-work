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

    void displayUnderFlowMessage()
    {
        cout << "Stack UnderFlow!" << endl;
    }

    void insertForSort(int value)
    {
        if (!isEmpty())
        {
            int top = peek();
            if (top > value)
            {
                pop();
                insertForSort(value);
                push(top);
            }
            else
                push(value);
        }
        else
            push(value);
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
            displayUnderFlowMessage();
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
            displayUnderFlowMessage();
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
            displayUnderFlowMessage();
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
            displayUnderFlowMessage();
            return INT_MIN;
        }
        else
            return top->data;
    }

    void insertAtBottom(int item)
    {
        if (isEmpty())
            push(item);
        else
        {
            int element = pop();
            insertAtBottom(item);
            push(element);
        }
    }

    void reverse()
    {
        if (!isEmpty())
        {
            int temp = pop();
            reverse();
            insertAtBottom(temp);
        }
    }

    void deleteStack()
    {
        if (isEmpty())
            displayUnderFlowMessage();
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

    void sort()
    {
        if (isEmpty())
            return;

        int value = pop();
        sort();
        insertForSort(value);
    }
};

int main()
{
    Stack *myStack = new Stack(5);
    myStack->push(10);
    // myStack->display();
    myStack->push(15);
    // myStack->display();
    myStack->push(12);
    // myStack->display();
    myStack->push(19);
    // myStack->display();
    myStack->push(26);
    // myStack->display();
    myStack->push(9);
    // myStack->display();

    myStack->reverse();
    myStack->display();
    myStack->sort();
    myStack->display();
    // cout << myStack->pop() << endl;
    // cout << myStack->pop() << endl;
    // cout << myStack->pop() << endl;
    // cout << myStack->pop() << endl;
    // cout << myStack->pop() << endl;
    // cout << myStack->pop() << endl;
    // cout << myStack->pop() << endl;
    // myStack->display();
    return 0;
}