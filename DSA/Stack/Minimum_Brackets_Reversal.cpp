#include <iostream>
#include <string>
#include <stack>

using namespace std;

int minimumBracketsReversal(string s)
{
    stack<char> st;
    int cnt = 0;
    if (s.length() % 2)
    {
        return -1;
    }

    // for (int i = 0; i < s.length(); i++)
    // {
    //     if (st.empty() && s[i] == ')')
    //     {
    //         st.push('(');
    //         cnt++;
    //     }
    //     else
    //     {
    //         if (s[i] == ')' && !st.empty())
    //         {
    //             st.pop();
    //         }
    //         else
    //         {
    //             st.push(s[i]);
    //         }
    //     }
    // }

    // if (st.size() % 2 == 0)
    // {
    //     cnt = cnt + st.size() / 2;
    // }
    // else
    // {
    //     cnt = cnt + st.size() / 2 + 1;
    // }
    // return cnt;

    for (char ch : s)
    {
        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }

    while (!st.empty())
    {
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();

        if (a == b)
        {
            cnt = cnt + 1;
        }
        else
        {
            cnt = cnt + 2;
        }
    }
    return cnt;
}

int main()
{
    // string s = ")(()))))";
    // string s = ")(())(((";
    // string s = "())(((";
    // string s = "(()((()(())((";
    // string s = "()))((";
    string s = "{}}{{{";
    cout << minimumBracketsReversal(s);

    return 0;
}