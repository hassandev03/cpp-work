#include <iostream>
using namespace ::std;
class Stack
{
private:
    int maxSize, noOfElements;
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
        noOfElements = 0;
        maxSize = size;
        stack = new int[maxSize];
    }

    bool isFull()
    {
        if (noOfElements == maxSize)
            return true;
        return false;
    }

    bool isEmpty()
    {
        if (noOfElements == 0)
            return true;
        return false;
    }

    void display()
    {
        if (isEmpty())
        {
            displayStackUnderFlowMessage();
            return;
        }
        cout << "--- Stack ---\n";
        for (int i = 0; i < noOfElements; i++)
        {
            cout << "    " << stack[i] << endl;
        }
        cout << endl;
    }

    void push(int data)
    {
        // ++top is don bcz initially top = -1, so it'll not add it in the array if
        // top++ is done
        if (isFull())
        {
            displayStackOverFlowMessage();
            return;
        }
        for (int i = noOfElements - 1; i >= 0; --i)
            stack[i + 1] = stack[i];
        stack[0] = data;
        noOfElements++;
    }

    int pop()
    {
        // first show the element then reposition (decrement) the top
        if (!isEmpty())
        {
            displayStackUnderFlowMessage();
            exit(1);
        }
        int poppedValue = stack[0];
        for (int i = 0; i < noOfElements; ++i)
            stack[i] = stack[i + 1];
        noOfElements--;
        return poppedValue;
    }

    int peek()
    {
        if (!isEmpty())
            return stack[0];
        else
        {
            displayStackUnderFlowMessage();
            exit(1);
        }
    }

    int getSize()
    {
        return (noOfElements);
    }

    int getMaxSize()
    {
        return maxSize;
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
    cout << myStack->peek() << endl;

    cout << myStack->pop() << endl;
    cout << myStack->pop() << endl;
    cout << myStack->pop() << endl;
    cout << myStack->pop() << endl;
    cout << myStack->pop() << endl;
    cout << myStack->pop() << endl;
    myStack->display();
    return 0;
}