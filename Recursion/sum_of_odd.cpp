#include <iostream>
using namespace ::std;

int oddSum(int n)
{
    if (n == 0)
        return 0;

    else if (n % 2 != 0)
        return n + oddSum(n - 1);

    return oddSum(--n);
}

int main()
{
    cout << oddSum(8);
    return 0;
}