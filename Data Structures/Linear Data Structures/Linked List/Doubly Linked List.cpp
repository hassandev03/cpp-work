#include <iostream>
using namespace ::std;
class DoublyLinkedList
{
private:
    int size;
    struct Node
    {
        int data;
        Node *prev = nullptr;
        Node *next = nullptr;
    };
    Node *head = nullptr, *tail = nullptr;

    // functionality methods of doubly linkedList
    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }

    void displayEmptyListMessage()
    {
        cout << "List does not exist!!" << endl;
    }

    // function for creating a node, as it is repeated everywhere
    Node *createNode(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        return newNode;
    }

    Node *search(int value)
    {
        if (isEmpty())
            return nullptr;
        else
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                if (temp->data == value)
                    return temp;
                temp = temp->next;
            }
            // if value not found
            return temp;
        }
    }

public:
    DoublyLinkedList()
    {
        size = 0;
    }
    DoublyLinkedList(int data)
    {
        size = 1;
        head = createNode(data);
        tail = head;
    }

    int getSize()
    {
        return size;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    void insertAtStart(int data)
    {
        if (isEmpty())
        {
            head = createNode(data);
            tail = head;
        }
        else
        {
            Node *newNode = createNode(data);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtEnd(int data)
    {
        if (isEmpty())
        {
            tail = createNode(data);
            head = tail;
        }
        else
        {
            tail->next = createNode(data);
            tail->next->prev = tail;
            tail = tail->next;
        }
        ++size;
    }

    void insertAtPosition(int data, int pos)
    {
        if (isEmpty())
            displayEmptyListMessage();
        else if (pos < 1 || pos > size)
            cout << "Invalid position!!" << endl;
        else
        {
            Node *temp = head;
            // we will insert after the temp node,
            // as first position has been handled abovewe'll start from second position
            for (int i = 1; i < pos && temp->next != nullptr; i++)
                temp = temp->next;

            Node *newNode = createNode(data);
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            ++size;
        }
    }

    void deleteLastNode()
    {
        if (isEmpty())
            displayEmptyListMessage();
        else if (size == 1)
        {
            delete tail;
            head = tail = nullptr;
            size--;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            temp = nullptr;
            size--;
        }
    }

    void deleteFirstNode()
    {
        if (isEmpty())
            displayEmptyListMessage();
        else if (size == 1)
        {
            delete head;
            head = tail = nullptr;
            size--;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
            size--;
        }
    }

    void deleteAtPosition(int pos)
    {
        int size = getSize();
        if (isEmpty())
            displayEmptyListMessage();
        else if (pos < 1 || pos > size)
            cout << "Invalid Position to be deleted" << endl;
        else
        {
            Node *temp = head;
            // we'll delete the node after temp node
            // as first position has been handled abovewe'll start from second position
            for (int i = 1; i < pos && temp->next != nullptr; i++)
                temp = temp->next;

            Node *newNode = temp, *prev = temp->prev, *next = temp->next;

            if (prev)
                prev->next = temp->next;
            if (next)
                next->prev = temp->prev;

            delete newNode;
            newNode = nullptr;
            size--;
        }
    }

    void reverseList()
    {
    }

    void swap(int value1, int value2)
    {
        if (isEmpty() || getSize() == 1 || value1 == value2)
        {
            cout << "Swap not possible!" << endl;
            return;
        }

        Node *first = search(value1);
        Node *second = search(value2);

        if (!first || !second)
        {
            cout << "Swap not possible!\nEither or all values not found!!" << endl;
            return;
        }

        // adjust head
        if (first->prev == nullptr)
            head = second;
        else if (second->prev == nullptr)
            head = first;

        // adjust tail
        if (first->next == nullptr)
            tail = second;
        else if (second->next == nullptr)
            tail = first;

        Node *temp;
        temp = first->prev;
        first->prev = second->prev;
        second->prev = temp;

        if (first->prev != nullptr)
            first->prev->next = first;
        if (second->prev != nullptr)
            second->prev->next = second;

        temp = first->next;
        first->next = second->next;
        second->next = temp;

        if (first->next)
            first->next->prev = first;
        if (second->next)
            second->next->prev = second;
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.insertAtStart(10);
    dll.insertAtStart(23);
    dll.insertAtStart(55);
    dll.insertAtEnd(75);
    dll.insertAtEnd(90);
    dll.insertAtEnd(32);
    // dll.printList();
    dll.insertAtPosition(67, 3);
    dll.insertAtPosition(101, 6);

    dll.deleteFirstNode();
    dll.deleteLastNode();
    dll.printList();

    dll.deleteAtPosition(5);
    dll.printList();

    dll.insertAtStart(155);
    dll.insertAtEnd(89);
    // dll.printList();

    dll.insertAtPosition(99, 4);
    dll.printList();
    cout << dll.getSize() << endl;
    dll.swap(89, 155);
    dll.printList();
    // dll.reverseList();
    // dll.printList();
}
