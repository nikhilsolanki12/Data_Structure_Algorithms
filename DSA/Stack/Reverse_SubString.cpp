#include <iostream>
#include <stack>

using namespace std;

string reverseParentheses(string &s)
{
    string ans = "";
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
    }
    int temp;
    while (!st.empty())
    {
        stack<char> tt;
        int i = st.top() + 1;
        while (s[i] != ')')
        {
            tt.push(s[i]);
            i++;
        }
        while (!tt.empty())
        {
            ans += tt.top();
            tt.pop();
        }
        s.replace(st.top(), ans.length() + 2, ans);
        st.pop();
        ans = "";
    }

    return s;
}

int main()
{
    // string s = "(abcd)";
    // string s = "(u(love)i)";
    string s = "(ed(et(oc))el)";

    s = reverseParanthesis(s);

    // s.replace(s.begin() + 2, s.end() - 2, "evol");
    // s.replace(0, 8, "iloveu");

    cout << s;

    return 0;
}