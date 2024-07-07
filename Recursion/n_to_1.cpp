#include <iostream>
using namespace ::std;

void n_to_1(int n)
{
    if (n == 0)
    {
        cout << endl;
        return;
    }

    cout << n << " ";
    n_to_1(n - 1);
}
int main()
{
    n_to_1(8);
    return 0;
}