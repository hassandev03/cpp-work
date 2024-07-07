#include <iostream>
#include <queue>
using namespace ::std;

class Dequeue
{
private:
    int currentSize, maxSize, front, rear;
    int *dequeue;

    void displayQueueOverFlowMessage()
    {
        cout << "Queue OverFlow!" << endl;
    }

    void displayQueueUnderFlowMessage()
    {
        cout << "Queue UnderFlow!" << endl;
    }

public:
    Dequeue(int size = 16)
    {
        front = rear = -1;
        currentSize = 0;
        maxSize = size;
        dequeue = new int[maxSize];
    }

    bool isFull()
    {
        // // if front is at zero, and rear is at last (maxSize - 1)th index
        // // or if rear is just behind the front, dequeue is full
        // // it will never be the case that rear is one ahead of front, and dequeue's full
        // return ((front == 0 && rear == (maxSize - 1)) || (front == (rear + 1)));

        return (currentSize == maxSize);
    }

    // for whole dequeue
    bool isEmpty()
    {
        // // if front and rear at -1
        // return (front == -1 && rear == -1);

        return (currentSize == 0);
    }

    int getSize()
    {
        return currentSize;
    }

    void display()
    {
        if (isEmpty())
            displayQueueUnderFlowMessage();
        else
        {
            cout << "\t--- Dequeue ---\n";
            for (int i = front, count = 0; count < currentSize; count++)
            {
                if (count == (currentSize - 1))
                    cout << dequeue[i];
                else
                    cout << dequeue[i] << " | ";
                i = (i + 1) % maxSize;
            }
            cout << endl;
        }
    }

    // insert at front end of dequeue
    void push(int value)
    {
        if (isFull())
            displayQueueOverFlowMessage();
        else
        {
            // if empty, or is at 0th index, so next element at left can only be inserted
            // by starting from last (maxSize -1)th index
            // if empty, make rear point towards the (maxSize -1)th index,
            // which is first in this case, to make ease in eject function
            if (isEmpty())
            {
                front = maxSize;
                rear = maxSize - 1;
            }
            else if (front == 0)
                front == maxSize;

            dequeue[--front] = value;
            currentSize++;
        }
    }

    // remove from front end of dequeue
    int pop()
    {
        if (isEmpty())
        {
            displayQueueUnderFlowMessage();
            exit(1);
        }
        else
        {
            int value = dequeue[front];

            // if only one element in the dequeue, reset the values;
            // if (front == rear)
            if (currentSize == 1)
                front = rear = -1;
            else
                front = (front + 1) % maxSize;
            currentSize--;
            return value;
        }
    }

    // insert at rear end of dequeue
    void inject(int value)
    {
        if (isFull())
            displayQueueOverFlowMessage();
        else
        {
            // if deque is empty, then make front at zero, so ease in pop operation
            if (isEmpty())
                front = 0;
            rear = (rear + 1) % maxSize;
            dequeue[rear] = value;
            currentSize++;
        }
    }

    // remove from rear end of dequeue
    int eject()
    {
        if (isEmpty())
        {
            displayQueueUnderFlowMessage();
            exit(1);
        }
        else
        {
            int value = dequeue[rear];

            // if only one element in the dequeue, reset the values;
            // if (front == rear)
            if (currentSize == 1) {
                front = -1;
                rear = 0;
            }
            // if more than one elements, rear at 0, then move it to maxSize
            // after that decrement it, and it will point to (maxSize-1)th index
            else if (rear == 0)
                rear = maxSize;

            rear--;
            currentSize--;
            return value;
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
            return dequeue[front];
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
            return dequeue[rear];
        }
    }

    ~Dequeue()
    {
        delete[] dequeue;
    }
};

int main()
{
    Dequeue *dq = new Dequeue(7);
    dq->push(6);
    dq->push(8);
    dq->inject(19);
    dq->push(7);
    dq->inject(51);
    dq->push(4);
    dq->inject(31);
    dq->display();

    dq->eject();
    dq->eject();
    dq->eject();
    dq->display();
    dq->eject();
    dq->display();
    dq->pop();
    dq->pop();
    dq->pop();
    dq->display();

    dq->inject(66);
    dq->push(44);

    dq->display();
    return 0;
}