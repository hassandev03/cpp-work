#include <iostream>
using namespace ::std;
void print(int arr[], int size);

void reverseArray(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArray(arr, ++start, end);
}
int main()
{
    int arr[] = {10, 15, 25, 30};
    print(arr, sizeof(arr) / sizeof(arr[0]));
    reverseArray(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    print(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}

void print(int arr[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
            cout << arr[i];
        else
            cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}