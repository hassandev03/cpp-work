#include <iostream>
using namespace ::std;

long findMax(int arr[], int n)
{
    if (n == 0)
        return arr[n];

    int num = findMax(arr, n - 1);

    return (arr[n] > num ? arr[n]: num);
}
int main()
{
    int arr[] = {10, 15, 30, 44};
    cout << findMax(arr, sizeof(arr) / sizeof(arr[0]) - 1);
    return 0;
}