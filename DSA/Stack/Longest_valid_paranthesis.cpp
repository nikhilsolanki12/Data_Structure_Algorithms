#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int longestValidParentheses(string s)
{
    int ans = 0;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < s.length(); i++)
    {
        int ch = s[i];
        if (ch == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int temp = i - st.top();
                ans = max(ans, temp);
            }
        }
    }
    return ans;
}
int main()
{
    // string s = "(()()()()()))))))))(((((((((((((((()))))))))))))((((((())))))))))))(((()()())()()";
    string s = "()()";
    // string s = "()(()";
    cout << longestValidParentheses(s);
    return 0;
}