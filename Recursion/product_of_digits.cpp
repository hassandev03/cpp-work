#include <iostream>
using namespace ::std;

long long productOfDigits(long long n)
{
    if (n % 10 == n) 
        return n;
    
    return (n % 10) * productOfDigits(n / 10);
}
int main()
{
    cout << productOfDigits(-157);
    return 0;
}