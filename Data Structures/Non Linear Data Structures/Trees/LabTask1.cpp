#include <iostream>
#include <math.h>
using namespace ::std;

struct Patient
{
    string name, contact, detail;
    int age;
    int condition;
};

class HospitalRegistrationSystem
{
private:
    int currIndex, maxSize;
    Patient *queue;

    bool isFull()
    {
        return (currIndex == maxSize - 1);
    }

    int parentIndex(int i)
    {
        return ((i - 1) / 2);
    }

    int rightChildIndex(int parentIndex)
    {
        return ((2 * parentIndex) + 2);
    }

    int leftChildIndex(int parentIndex)
    {
        return ((2 * parentIndex) + 1);
    }

    void extendCapacity()
    {
        int newSize = 2 * maxSize;
        Patient *arr = new Patient[newSize];

        for (int i = 0; i < maxSize; i++)
            arr[i] = queue[i];

        delete[] queue;
        queue = arr;
        arr = nullptr;
    }

    void swap(int parentIndex, int childIndex)
    {
        Patient temp = queue[parentIndex];
        queue[parentIndex] = queue[childIndex];
        queue[childIndex] = temp;
    }

    void shiftUp()
    {
        int i = currIndex;
        while (i > 0 && queue[parentIndex(i)].condition > queue[currIndex].condition)
        {
            swap(parentIndex(i), i);
            i = parentIndex(i);
        }
    }

    void shiftDown(int curr)
    {
        int maxValIndex = curr;

        int right = rightChildIndex(maxValIndex), left = leftChildIndex(maxValIndex);

        maxValIndex = (left <= currIndex && queue[left].condition > queue[maxValIndex].condition) ? left : maxValIndex;
        maxValIndex = (right <= currIndex && queue[right].condition > queue[maxValIndex].condition) ? right : maxValIndex;

        if (curr != maxValIndex)
        {
            swap(curr, maxValIndex);
            shiftDown(maxValIndex);
        }
    }

    void displayPatient(Patient p)
    {
        cout << "Name: " << p.name << endl;
        cout << "Age: " << p.age << endl;
        cout << "Contact: " << p.contact << endl;
        cout << "Detail: " << p.detail << endl;
    }

    void display()
    {
        for (int i = 0; i < sizeof(queue) / sizeof(queue[0]); i++)
            displayPatient(queue[i]);
    }

public:
    HospitalRegistrationSystem(int size = 16)
    {
        maxSize = size;
        currIndex = -1;
        queue = new Patient[maxSize];
    }

    void admitPatient(Patient key)
    {
        if (isFull())
            extendCapacity();

        queue[++currIndex] = key;
        shiftUp();
    }

    void mostCriticalPatient()
    {
        Patient p = queue[currIndex];

        queue[currIndex--] = queue[0];
        queue[0] = p;

        shiftDown(0);
        displayPatient(p);
    }

    static Patient createPatient()
    {
        Patient p;
        cout << "Enter Name: ";
        cin >> p.name;

        cout << "Enter Age: ";
        cin >> p.age;
        cin.ignore();

        cout << "Enter Contact: ";
        cin >> p.contact;
        cin.ignore();

        cout << "Enter additional Details regarding Patient: ";
        getline(cin, p.detail);

        cout << "What is the condition of Patient:\nEmergency(Enter 4)\nCritical(Enter 3)\nSerious(Enter 2)\nJust Sick(Enter 1)" << endl;
        cin >> p.condition;
        cin.ignore();

        return p;
    }
};

int main()
{
    HospitalRegistrationSystem h;
    h.admitPatient(h.createPatient());
    h.admitPatient(h.createPatient());
    h.admitPatient(h.createPatient());
    h.admitPatient(h.createPatient());
    h.admitPatient(h.createPatient());
    h.admitPatient(h.createPatient());
    h.mostCriticalPatient();
}