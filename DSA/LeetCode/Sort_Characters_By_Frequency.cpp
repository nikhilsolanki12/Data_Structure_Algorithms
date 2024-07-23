#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s = "absbab";
    sort(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i];
    }
    return 0;
}