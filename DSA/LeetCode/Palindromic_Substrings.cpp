#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int countSubstrings(string s)
{
    vector<string> ans;
    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = s.length(); j >= i; j--)
        {
            string s1 = s.substr(i, s.length() - j);
            string s2 = s1;
            reverse(s1.begin(), s1.end());
            if (s1.length() && s1 == s2)
            {
                cout << s1 << "  " << s2 << endl;
                ans.push_back(s1);
            }
        }
    }

    return ans.size();
}

int main()
{
    string s = "nikhil";
    int cnt = countSubstrings(s);
    string s1 = s;
    // reverse(s1.begin(), s1.end());

    // cout << s << " " << s1 << endl;
    cout << cnt;
    return 0;
}