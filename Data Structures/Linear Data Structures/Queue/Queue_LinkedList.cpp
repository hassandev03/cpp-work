#include <iostream>
using namespace ::std;

class Queue
{
private:
    struct Node
    {
        int data;
        Node *link = nullptr;
    };
    Node *front = nullptr, *rear = nullptr;

    void displayQueueUnderFlowMessage()
    {
        cout << "Queue is Empty!" << endl;
    }

public:
    Queue()
    {
    }

    Queue(int data)
    {
        enqueue(data);
    }

    bool isEmpty()
    {
        return (front == nullptr);
    }

    int getSize()
    {
        if (isEmpty())
            displayQueueUnderFlowMessage();
        else
        {
            Node *temp = front;
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
            displayQueueUnderFlowMessage();
        else
        {
            cout << "--- Queue ---\n| ";
            Node *temp = front;
            while (temp != nullptr)
            {
                cout << temp->data << " | ";
                temp = temp->link;
            }
            cout << endl;
        }
    }

    void enqueue(int data)
    {
        if (isEmpty())
        {
            front = new Node;
            front->data = data;
            rear = front;
        }
        else
        {
            rear->link = new Node;
            rear->link->data = data;
            rear = rear->link;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            displayQueueUnderFlowMessage();
            exit(1);
        }
        else
        {
            Node *temp = front;
            front = front->link;
            int value = temp->data;
            delete temp;
            return value;
        }
    }

    void deleteQueue()
    {
        if (isEmpty())
            displayQueueUnderFlowMessage();
        else
        {
            Node *next = front;
            while (next != nullptr)
            {
                dequeue();
                next = next->link;
            }
            cout << "Queue successfully deleted!" << endl;
        }
    }
};

int main()
{
    Queue *q2 = new Queue(8);
    q2->enqueue(7);
    q2->enqueue(6);
    q2->enqueue(15);
    q2->enqueue(9);
    q2->enqueue(10);
    q2->display();
    q2->dequeue();
    q2->display();
    return 0;
}