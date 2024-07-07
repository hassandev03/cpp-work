#include <iostream>
using namespace ::std;

long long sumNToOne(long long n)
{
    if (n == 0 || n == 1) 
        return 1;
    
    return n + sumNToOne(n - 1);
}
int main()
{
    cout << sumNToOne(8);
    return 0;
}