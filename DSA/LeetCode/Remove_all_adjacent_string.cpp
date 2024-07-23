#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string removeAdjacent(string s)
{
    string s1 = "";
    stack<char> st;
    if (s.length() != 0)
        st.push(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if (st.empty() || s[i] != st.top())
        {
            st.push(s[i]);
            cout << "Push Successfully :" << st.top() << endl;
        }
        else
        {
            cout << "Pop successfully : " << st.top() << endl;
            st.pop();
        }
    }

    while (!st.empty())
    {
        char c[1] = {st.top()};

        s1.append(c);
        st.pop();
    }
    s1.append("\0");
    reverse(s1.begin(), s1.end());
    return s1;
}

int main()
{
    string s = "aabbccc";
    cout << removeAdjacent(s);
}