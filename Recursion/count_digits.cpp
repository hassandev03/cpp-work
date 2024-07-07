#include <iostream>
using namespace ::std;

int countDigits(long long n)
{
    if (n % 10 == n)
        return 1;

    return 1 + countDigits(n / 10);
}
int main()
{
    cout << countDigits(-157);
    return 0;
}