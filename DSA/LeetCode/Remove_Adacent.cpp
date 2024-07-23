#include <iostream>
#include <string>

using namespace std;

string removeDuplicate(string s)
{
    int i = 0;
    string ans = "";
    // cout << s[0]<<endl;
    while (i < s.length())
    {
        if (s[i] == s[i + 1])
            i = i + 2;
        else
        {
            if (ans.length() == 0 || ans[ans.length() - 1] != s[i])

                ans.push_back(s[i]);
            else

                ans.pop_back();
            i++;
        }
    }
    return ans;
}

int main()
{
    string s = "azxxzy";
    s = removeDuplicate(s);
    // s.erase(0, 2);
    cout << s;

    return 0;
}