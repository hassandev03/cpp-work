#include <iostream>
using namespace ::std;

long long power(int num, int pow)
{
    if (pow == 1) 
        return num;
    
    return num * power(num, pow - 1);
}
int main()
{
    cout << power(7, 3);
    return 0;
}