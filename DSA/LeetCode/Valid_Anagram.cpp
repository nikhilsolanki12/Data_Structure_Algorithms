#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool validAnagram(string &s1, string &s2)
{
    sort(s1.begin(), s1.end());

    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

int main()
{
    string s1 = "silent";
    string s2 = "listen";

    cout << validAnagram(s1, s2);

    return 0;
}