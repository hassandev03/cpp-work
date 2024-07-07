#include <iostream>
using namespace ::std;

int i = 2;
bool isPrime(long long n)
{
    if (n < 2 || n % i == 0)
        return false;
    else if (i * i > n)
        return true;

    ++i;
    return isPrime(n);
}
int main()
{
    cout << isPrime(31);
    return 0;
}