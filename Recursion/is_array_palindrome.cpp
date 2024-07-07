#include <iostream>
using namespace ::std;

long isPalindrome(int arr[], int start, int end)
{
    if (start >= end)
        return true;
    else if (arr[start] != arr[end])
        return false;

    return isPalindrome(arr, ++start, --end);
}

int main()
{
    int arr[] = {51, 15, 17, 20, 15, 51};
    cout << isPalindrome(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    return 0;
}