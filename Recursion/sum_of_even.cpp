#include <iostream>
using namespace ::std;

int evenSum(int n)
{
    if (n == 0)
        return 0;

    else if (n % 2 == 0)
        return n + evenSum(n - 1);

    return evenSum(--n);
}
int main()
{
    cout << evenSum(8);
    return 0;
}