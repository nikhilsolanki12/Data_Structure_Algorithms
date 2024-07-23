#include <iostream>
#include <stack>

using namespace std;

bool validParanthesis(string &s)
{
    stack<char> s1;
    if (s.length() % 2 != 0)
        return false;
    for (int i = 0; i < s.length(); i++)
    {
        s1.push(s[i]);
        if (s[i] == '(' && s[i + 1] == ')')
        {

            s1.pop();
            i++;
        }
        if (s[i] == '[' && s[i + 1] == ']')
        {

            s1.pop();
            i++;
        }
        if (s[i] == '{' && s[i + 1] == '}')
        {

            s1.pop();
            i++;
        }
        if (!s1.empty())
            return false;
    }
    if (s1.empty())
        return true;
    return false;
}
int main()
{
    string s = "{}{{";

    cout << validParanthesis(s);

    return 0;
}