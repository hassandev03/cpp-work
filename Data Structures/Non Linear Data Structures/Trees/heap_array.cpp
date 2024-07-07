#include <iostream>
#include <math.h>
using namespace ::std;

// it is min Priority Queue
class MaxHeap
{
private:
    int size, maxSize, *queue;

    bool isFull()
    {
        return (size == maxSize - 1);
    }

    int parentIndex(int i)
    {
        return ((i - 1) / 2);
    }

    int rightChildIndex(int parent)
    {
        return ((2 * parent) + 2);
    }

    int leftChildIndex(int parent)
    {
        return ((2 * parent) + 1);
    }

    void extendCapacity()
    {
        int newSize = maxSize + ceil(maxSize / 2);
        int *arr = new int[newSize];

        for (int i = 0; i < maxSize; i++)
            arr[i] = queue[i];

        delete[] queue;
        queue = arr;
        arr = nullptr;
    }

    void swap(int parentIndex, int childIndex)
    {
        int temp = queue[parentIndex];
        queue[parentIndex] = queue[childIndex];
        queue[childIndex] = temp;
    }

    void shiftUp()
    {
        int i = size;
        while (i > 0 && queue[parentIndex(i)] >= queue[size])
        {
            swap(parentIndex(i), i);
            i = parentIndex(i);
        }
    }

    void shiftDown(int curr)
    {
        int left = leftChildIndex(curr), right = rightChildIndex(curr), smallest = curr;

        smallest = (left < maxSize && queue[left] < queue[smallest]) ? left : smallest;
        smallest = (right < maxSize && queue[right] < queue[smallest]) ? right : smallest;

        if (smallest != curr)
        {
            swap(queue[curr], queue[smallest]);
            shiftDown(smallest);
        }
    }

public:
    MaxHeap(int inpSize = 16)
    {
        maxSize = inpSize;
        size = -1;
        queue = new int[maxSize];
    }

    void insert(int key)
    {
        if (isFull())
            extendCapacity();

        queue[++size] = key;
        shiftUp();
    }

    int extractMin()
    {
        int returnValue = queue[0];
        queue[0] = queue[size--];

        shiftDown(0);
        return returnValue;
    }
};

int main()
{
    MaxHeap mh;
    mh.insert(19);
    mh.insert(60);
    mh.insert(12);
    mh.insert(42);
    mh.insert(53);
    mh.insert(27);
    mh.insert(32);

   cout << mh.extractMin();
}