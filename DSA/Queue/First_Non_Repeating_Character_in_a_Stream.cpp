

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

string First_Non_Repeating_Character(string s)
{
    string ans;
    queue<char> ch;
    vector<int> n(26);

    for (int i = 0; i < s.length(); i++)
    {

        n[s[i] - 'a']++;
        ch.push(s[i]);

        while (!ch.empty())
        {
            if (n[ch.front() - 'a'] > 1)
            {
                ch.pop();
            }
            else
            {
                ans += ch.front();
                break;
            }
        }
        if (ch.empty())
            ans += '#';
    }
    ans.append("\0");
    return ans;
}

int main()
{

    // string s = "aabbbc";
    string s = "zarcaazrd";
    cout << First_Non_Repeating_Character(s);

    return 0;
}