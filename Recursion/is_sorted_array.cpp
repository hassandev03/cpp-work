#include <iostream>
using namespace ::std;

long isSorted(int arr[], int n)
{
    if (n == 0)
        return true;
    else if (arr[n] < arr[n - 1])
        return false;

    return isSorted(arr, --n);
}
int main()
{
    int arr[] = {18, 15, 19, 44, 50, 51};
    cout << isSorted(arr, sizeof(arr) / sizeof(arr[0]) - 1);
    return 0;
}