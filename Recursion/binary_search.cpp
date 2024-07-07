#include <iostream>
using namespace ::std;

int binarySearch(int num, int low, int high, int arr[])
{

    if (low > high)
        return -1;

    int mid = (high + low) / 2;

    if (arr[mid] == num)
        return mid;
    else if (num > arr[mid])
        return binarySearch(num, mid + 1, high, arr);
    else
        return binarySearch(num, low, mid - 1, arr);
}
int main()
{
    int arr[] = {5, 7, 9, 11, 15, 20};
    cout << binarySearch(12, 0, sizeof(arr) / sizeof(arr[0]) - 1, arr);
    return 0;
}