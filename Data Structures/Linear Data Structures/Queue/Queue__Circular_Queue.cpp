#include <iostream>
using namespace ::std;
class Queue
{
private:
    int currentSize, maxSize, rear, front;
    int *queue;

    void displayQueueOverFlowMessage()
    {
        cout << "Queue OverFlow!" << endl;
    }

    void displayQueueUnderFlowMessage()
    {
        cout << "Queue UnderFlow!" << endl;
    }

public:
    Queue(int size = 16)
    {
        currentSize = 0;
        front = rear = -1;
        maxSize = size;
        queue = new int[maxSize];
    }

    int getSize()
    {
        return currentSize;
    }

    int getMaxSize()
    {
        return maxSize;
    }
    bool isFull()
    {
        return (currentSize == maxSize);
    }

    bool isEmpty()
    {
        return (currentSize == 0);
    }

    void display()
    {
        if (isEmpty())
            displayQueueUnderFlowMessage();
        else
        {
            cout << "\t--- Queue ---\n| ";
            for (int i = front, cnt = 0; cnt < currentSize;)
            {
                cout << queue[i] << " | ";
                i = (i + 1) % maxSize;
                cnt++;
            }
            cout << endl;
        }
    }

    void enqueue(int data)
    {
        if (isFull())
            displayQueueOverFlowMessage();
        else
        {
            rear = (rear + 1) % maxSize;
            if (isEmpty())
                front = 0;
            queue[rear] = data;
            currentSize++;
        }
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            int value = queue[front];
            front = (front + 1) % maxSize;
            currentSize--;
            return value;
        }
        else
        {
            displayQueueUnderFlowMessage();
            exit(1);
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            displayQueueUnderFlowMessage();
            exit(1);
        }
        else
        {
            return queue[front];
        }
    }

    int back()
    {
        if (isEmpty())
        {
            displayQueueUnderFlowMessage();
            exit(1);
        }
        else
        {
            return queue[rear];
        }
    }

    void reverse()
    {
        if (isEmpty())
            return;

        int data = dequeue();
        reverse();
        enqueue(data);
    }
    ~Queue()
    {
        delete[] queue;
    }
};

int main()
{
    Queue q2(5);
    q2.enqueue(7);
    q2.enqueue(6);
    q2.enqueue(15);
    q2.enqueue(9);
    q2.display();
    cout << q2.dequeue() << endl;
    cout << q2.dequeue() << endl;
    cout << q2.dequeue() << endl;
    q2.enqueue(10);
    // cout << q2.dequeue() << endl;
    // q2.dequeue();
    // q2.display();

    // q2.reverse();
    q2.display();
    return 0;
}