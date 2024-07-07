#include <iostream>
using namespace ::std;

long countOccurance(int arr[], int target, int n)
{
    if (n == -1)
        return 0;
    else if (arr[n] == target)
        return 1 + countOccurance(arr, target, --n);
    else
        return countOccurance(arr, target, --n);
}
int main()
{
    int arr[] = {10, 15, 25, 30, 10, 15, 10, 44};
    cout << countOccurance(arr, 10, sizeof(arr) / sizeof(arr[0]) - 1);
    return 0;
}