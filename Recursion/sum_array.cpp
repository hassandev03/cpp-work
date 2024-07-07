#include <iostream>
using namespace ::std;

long sumArray(int arr[], int start, int size)
{
    if (start == size) 
        return 0;
    
    return arr[start] + sumArray(arr, ++start, size);
}
int main()
{
    int arr[] = {10, 15, 25, 30};
    cout << sumArray(arr,0, sizeof(arr)/sizeof(arr[0]));
    return 0;
}