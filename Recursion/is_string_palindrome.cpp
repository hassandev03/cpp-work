#include <iostream>
using namespace ::std;

char toLowerCase(char ch)
{
    if ('A' <= ch && ch <= 'Z')
        return (ch - 'A' + 'a');
    return ch;
}

bool palindrome(string str, int start)
{
    int high = str.size() - start - 1;
    if (start >= high)
        return true;

    if (toLowerCase(str[start]) != toLowerCase(str[high]))
        return false;

    return palindrome(str, ++start);
}
int main()
{
    cout << palindrome("Hassah", 0);
    return 0;
}