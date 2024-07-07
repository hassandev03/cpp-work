#include <iostream>
using namespace ::std;
class Stack
{
private:
    int maxSize;
    int top;
    int *stack;

    void displayStackOverFlowMessage()
    {
        cout << "Stack OverFlow!" << endl;
    }

    void displayStackUnderFlowMessage()
    {
        cout << "Stack UnderFlow!" << endl;
    }

public:
    Stack(int size = 16)
    {
        top = -1;
        maxSize = size;
        stack = new int[maxSize];
    }

    bool isFull()
    {
        return (top == (maxSize - 1));
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    void display()
    {
        if (isEmpty())
        {
            displayStackUnderFlowMessage();
            return;
        }
        cout << "--- Stack ---\n";
        for (int i = top; i >= 0; i--)
        {
            cout <<  stack[i] << "    " << endl;
        }
        cout << endl;
    }

    void push(int data)
    {
        // ++top is don bcz initially top = -1, so it'll not add it in the array if
        // top++ is done
        if (!isFull())
            stack[++top] = data;
        else
            displayStackOverFlowMessage();
    }

    int pop()
    {
        // first show the element then reposition (decrement) the top
        if (!isEmpty())
            return stack[top--];
        else
        {
            displayStackUnderFlowMessage();
            exit(1);
        }
    }

    int peek()
    {
        if (!isEmpty())
            return stack[top];
        else
        {
            displayStackUnderFlowMessage();
            exit(1);
        }
    }

    int getSize()
    {
        return (top + 1);
    }

    int getMaxSize()
    {
        return maxSize;
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

    ~Stack()
    {
        delete[] stack;
    }
};

int main()
{
    Stack *myStack = new Stack(6);
    myStack->push(10);
    myStack->display();
    myStack->push(15);
    myStack->display();
    myStack->push(12);
    myStack->display();
    myStack->push(19);
    myStack->display();
    myStack->push(26);
    myStack->display();
    myStack->push(9);
    myStack->display();

    myStack->reverse();
    myStack->display();

    return 0;
}