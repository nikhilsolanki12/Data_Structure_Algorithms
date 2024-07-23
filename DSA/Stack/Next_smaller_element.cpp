#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> v)
{

    // broth force
    vector<int> ans(v.size());

    // for (int i = 0; i < v.size(); i++)
    // {
    //     int temp = v[i];
    //     for (int j = i; j < v.size(); j++)
    //     {
    //         temp = min(temp, v[j]);
    //     }
    //     if (temp == v[i])
    //     {
    //         ans.push_back(-1);
    //     }
    //     else
    //     {
    //         ans.push_back(temp);
    //     }
    // }

    // using stack
    stack<int> st;
    st.push(-1);
    for (int i = v.size() - 1; i >= 0;)
    {
        if (v[i] > st.top())
        {
            ans[i] = st.top();
            st.push(v[i]);
            i--;
        }
        else
        {
            st.pop();
        }
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> v)
{

    // broth force
    vector<int> ans(v.size());

    // using stack
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < v.size();)
    {
        if (v[i] > st.top())
        {
            ans[i] = st.top();
            st.push(v[i]);
            i++;
        }
        else
        {
            st.pop();
        }
    }

    return ans;
}

int main()
{

    vector<int> s1 = {2, 1, 5, 6, 2, 3};
    vector<int> ans = nextSmallerElement(s1);
    vector<int> ans2 = prevSmallerElement(s1);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }
}
