#include <iostream>
using namespace ::std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *link = nullptr;
    };
    Node *head = nullptr, *tail = nullptr;

    bool isEmpty()
    {
        return (head == nullptr);
    }

    void displayEmptyListMessage()
    {
        cout << "List does not exist!!" << endl;
    }

    Node *search(int value)
    {
        if (isEmpty())
            return nullptr;
        else
        {
            Node *newNode = head;
            // iterate through the list and check whether the current node is empty and currentNode data equals the value
            while (newNode != nullptr && newNode->data != value)
                newNode = newNode->link;

            return newNode;
        }
    }

public:
    LinkedList()
    {
    }
    LinkedList(int value)
    {
        insertAtStart(value);
    }

    Node *getHead()
    {
        return head;
    }

    void display()
    {
        // if list is empty
        if (isEmpty())
            displayEmptyListMessage();
        else
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " -> ";
                temp = temp->link;
            }
            cout << "null" << endl;
        }
    }

    int listLength()
    {
        if (isEmpty())
            return 0;
        else
        {
            int count = 0;
            Node *temp = head;
            while (temp != nullptr)
            {
                temp = temp->link;
                count++;
            }
            return count;
        }
    }

    void insertAtStart(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        // no need to assign link to null as it is already pointed to null in the struct

        if (head == nullptr)
            head = tail = newNode;
        else
        {
            // assign the current first node to>link of newNode to make newNode before the current first
            newNode->link = head;
            // now as the newNode is the first, point the first to newNode
            head = newNode;
        }
    }

    void insertAtEnd(int value)
    {
        // check if list is empty
        if (isEmpty())
        {
            head = new Node;
            head->data = value;
            tail = head;
        }
        else
        {
            tail->link = new Node;
            tail->link->data = value;
            tail = tail->link;
            // Node *temp = head;
            // while (temp->link != nullptr)
            // {
            //     temp = temp->link;
            // }
            // temp->link = new Node;
            // temp->link->data = value;
            // tail = temp->link;
            // no need to assign link to null as it is already pointed to null in the struct
        }
    }

    void insertBeforeValue(int value, int insertValue)
    {
        // if list empty
        if (isEmpty())
            displayEmptyListMessage();
        else if (head->data == value)
            insertAtStart(insertValue);
        else
        {
            Node *temp = head;
            while (temp->link != nullptr && temp->link->data != value)
                temp = temp->link;

            if (temp->link == nullptr)
                cout << "Value not found in the List!" << endl;
            else
            {
                Node *newNode = new Node;
                newNode->data = insertValue;
                newNode->link = temp->link;
                temp->link = newNode;
            }
        }
    }

    void insertAfterValue(int value, int insertValue)
    {
        // if list empty
        if (isEmpty())
        {
            displayEmptyListMessage();
        }
        // if ending value
        if (tail->data == value)
        {
            insertAtEnd(insertValue);
        }
        else
        {
            Node *valueNode = search(value);
            if (valueNode == nullptr)
                cout << "Value doesn't exist in the list!!" << endl;
            else
            {
                Node *newNode = new Node;
                newNode->data = insertValue;
                newNode->link = valueNode->link;
                valueNode->link = newNode;
            }
        }
    }

    void deleteFirstNode()
    {
        // if list empty
        if (isEmpty())
            displayEmptyListMessage();
        else
        {
            Node *newNode = head;
            // before deleting or assigning first to a new location, point the memory location of first to another node
            // so that it gets a reference and we can delete it
            head = head->link;
            delete newNode;
        }
    }

    void deleteLastNode()
    {
        // if list empty
        if (isEmpty())
            displayEmptyListMessage();
        // if only one node
        else if (head == tail)
        {
            delete head, tail;
            head = tail = nullptr;
        }
        else
        {
            Node *last = head;

            while (last->link->link != nullptr)
                last = last->link;

            delete last->link;
            last->link = nullptr;
            tail = last;
        }
    }

    void deleteValue(int value)
    {
        // if list empty
        if (isEmpty())
            displayEmptyListMessage();
        else if (head->data == value)
            deleteFirstNode();
        else if (tail->data == value)
            deleteLastNode();
        else
        {
            Node *temp = head;
            while (temp->link != nullptr && temp->link->data != value)
                temp = temp->link;

            if (temp->link == nullptr)
                cout << "No such value exists in the list!!" << endl;
            else
            {
                // assign newNode to node that is to be deleted
                Node *newNode = temp->link;
                // assign link of temp to the node that is after the deletion node
                temp->link = newNode->link;
                delete newNode;
            }
        }
    }

    void deleteBeforeValue(int value)
    {
        // if list empty
        if (isEmpty())
            displayEmptyListMessage();
        else if (head->data == value)
            cout << "Cannot delete before first node!!\nAs no value exists before first node" << endl;
        else
        {
            Node *deleteNode = head, *prev = nullptr;

            while (deleteNode->link != nullptr && deleteNode->link->data != value)
            {
                prev = deleteNode;
                deleteNode = deleteNode->link;
            }

            if (deleteNode->link == nullptr)
                cout << "No such value exists in the list!!" << endl;
            else
            {
                prev->link = deleteNode->link;
                delete deleteNode;
            }
        }
    }

    void deleteAfterValue(int value)
    {
        // if list empty
        if (isEmpty())
            displayEmptyListMessage();
        else if (tail->data == value)
            cout << "Cannot delete after last node!!\nAs no value exists after last node" << endl;
        else
        {
            Node *temp = search(value);
            if (temp == nullptr)
            {
                cout << "No such value exists in the list!!" << endl;
            }
            else
            {
                Node *newNode = temp->link;
                temp->link = newNode->link;
                delete newNode;

                // if you deleted the last node, update the tail
                if (temp->link == nullptr)
                    tail = temp;
            }
        }
    }

    void reverseList()
    {
        // if list empty
        if (isEmpty())
            displayEmptyListMessage();
        else if (head == tail)
            cout << "Insufficient elements to reverse!!" << endl;
        else
        {

            Node *current = head, *tempPrev = nullptr, *tempNext = nullptr;
            while (current != nullptr)
            {
                tempNext = current->link;
                current->link = tempPrev;
                tempPrev = current;
                current = tempNext;
            }
            tail = head;
            head = tempPrev;
            tempPrev = nullptr;
        }
    }

    // swap function
    void swapValues(Node *first, Node *second)
    {
        Node *temp = new Node;
        temp->data = first->data;
        first->data = second->data;
        second->data = temp->data;

        // prevent memory leak
        delete temp;
        temp = nullptr;
    }

    void reverseListByValues()
    {
        // if list empty
        if (isEmpty())
            displayEmptyListMessage();
        else if (head == tail)
            cout << "Insufficient elements to reverse!!" << endl;
        else
        {
            Node *start = head, *secondLast = nullptr, *last = tail->link;
            int size = listLength();
            for (int i = 0; i < size / 2; i++)
            {
                secondLast = start;
                while (secondLast->link != last)
                    secondLast = secondLast->link;

                swapValues(start, secondLast);
                start = start->link;
                last = secondLast;
            }
        }
    }

    void reversePrint()
    {
        Node *next = nullptr, *temp = nullptr;
        if (isEmpty())
            cout << "List is Empty!!" << endl;
        else if (head->link == nullptr)
            cout << "Insufficient elements to reverse print!!" << endl;
        else
        {
            while (next != head)
            {
                temp = head;
                while (temp->link != next)
                    temp = temp->link;

                cout << temp->data << " -> ";
                next = temp;
            }
            cout << "null" << endl;
        }
    }

    void deleteList()
    {
        Node *temp = nullptr;
        while (head != nullptr)
        {
            temp = head;
            // cannot delete temp before, because head and temp are pointing to same
            // memory location so deleting temp memory location will also delete head one
            head = head->link;
            delete temp;
        }
        tail = head;
    }

    void reverse(Node *node)
    {
        if (!node || !node->link)
        {
            head = node;
            return;
        }
        Node *next = node->link;
        reverse(next);

        node->link->link = node;
        node->link = nullptr;
        tail = node;
    }
};

int main()
{
    LinkedList list(10);
    // list.insertAtEnd(1);
    // list.insertAtEnd(2);
    // list.insertAtEnd(3);
    // list.insertAtEnd(4);
    list.insertAtStart(5);
    // list.insertAtStart(6);

    // list.display();
    // list.reverseList();
    // list.display();
    list.insertAtEnd(66);
    // list.insertAtStart(64);
    // list.display();

    // list.deleteLastNode();
    // list.display();
    // list.deleteFirstNode();
    // list.display();
    // list.insertAtEnd(65);
    list.insertAtStart(321);
    // list.insertAtStart(765);
    list.insertAtEnd(774);
    // list.display();
    // list.deleteAfterValue(65);
    // list.insertBeforeValue(321, 5476);
    // list.display();
    //    list.reverseList();
    // list.display();
    // list.insertAtEnd(111);
    // list.insertAfterValue(321, 543);
    // list.display();
    //    list.deleteList();
    list.display();
    // list.reversePrint();
    // list.reverseListByValues();
    list.reverse(list.getHead());
    list.display();
}
