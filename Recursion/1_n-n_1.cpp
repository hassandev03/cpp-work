#include <iostream>
using namespace ::std;

void one_n_one(int n)
{
    if (n == 0) {
        cout << endl;
        return;
    }

    cout << n << " ";
    one_n_one(n - 1);
    cout << n << " ";
}
int main()
{
    one_n_one(8);
    return 0;
}