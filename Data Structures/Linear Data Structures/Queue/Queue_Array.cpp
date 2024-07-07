#include <iostream>
using namespace ::std;
class Queue
{
private:
    int maxSize;
    int rear, front;
    int *queue;

    void displayQueueOverFlowMessage()
    {
        cout << "Queue is Full!" << endl;
    }

    void displayQueueUnderFlowMessage()
    {
        cout << "Queue is Empty!" << endl;
    }

    void shiftLeft()
    {
        int i;
        for (i = 0; front <= rear; i++)
        {
            queue[i] = queue[front++];
        }
        front = 0;
        rear = i - 1;
    }

public:
    Queue(int size = 16)
    {
        rear = -1;
        front = -1;
        maxSize = size;
        queue = new int[maxSize];
    }

    int getSize()
    {
        return (rear + 1);
    }

    int getMaxSize()
    {
        return maxSize;
    }
    bool isFull()
    {
        if (rear == (maxSize - 1))
            return true;
        return false;
    }

    bool isEmpty()
    {
        if (front == -1 || rear < front)
            return true;
        return false;
    }

    void display()
    {
        if (isEmpty())
            displayQueueUnderFlowMessage();
        else
        {
            cout << "\t--- Queue1 ---\n| ";
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " | ";
            }
            cout << endl;
        }
    }

    void enqueue(int data)
    {
        if (isEmpty())
        {
            front = 0;
            rear = -1;
        }
        else if (rear == (maxSize - 1) && front > 0)
        {
            shiftLeft();
        }
        if (!isFull())
            queue[++rear] = data;
        else
            displayQueueOverFlowMessage();
    }

    int dequeue()
    {
        // first show the element then reposition (decrement) the rear
        if (!isEmpty())
            return queue[front++];
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

    void reverse()
    {
        if (isEmpty())
        {
            front = rear = -1;
            return;
        }

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
    Queue q2(7);
    q2.enqueue(7);
    q2.enqueue(6);
    q2.enqueue(15);
    q2.enqueue(9);
    q2.enqueue(91);
    q2.enqueue(20);
    q2.enqueue(12);
    q2.display();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.enqueue(10);
    q2.display();
    q2.dequeue();
    q2.display();

    // q2.reverse();
    return 0;
}