#include <iostream>
using namespace ::std;

long long factorial(long long n)
{
    if (n == 0 || n == 1) 
        return 1;
    
    return n * factorial(n - 1);
}
int main()
{
    cout << factorial(15);
    return 0;
}