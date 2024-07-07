#include <iostream>
using namespace ::std;

string reverseString(string str)
{
    if (str.size() == 0 || str.size() == 1)
        return str;


    return reverseString(str.substr(1)) + str[0];
}
int main()
{
    cout << reverseString("string");
    return 0;
}