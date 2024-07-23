// A celebrity is a person who is known to alllbut does not know anyone at a party. If you
// go to a party of N people, find if there is a celebrity in the party or not.
// A square NXN matrix MI I [ ] is used to represent people at the party such that if an
// element of rowi and column j is set to 1 it means ith person knowsjth person. Here
// M[i] [i] will always be 0.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    // cout << st.size() << endl;

    while (st.size() != 1)
    {
        int s = st.top();
        st.pop();
        int k = st.top();
        st.pop();

        if (M[s][k])
        {
            st.push(k);
        }
        else
        {
            st.push(s);
        }
    }

    int t = st.top();

    for (int i = 0; i < M.size(); i++)
    {
        if (M[t][i] != 0 && i != t)
            return -1;
    }
    return st.top();
}

int main()
{
    vector<vector<int>> M{{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
    cout << celebrity(M, 4) << " is Celebrity";
    return 0;
}