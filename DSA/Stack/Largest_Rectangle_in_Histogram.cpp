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
    stack<int> st1;
    int maximum = -1;
    st.push(-1);
    st1.push(-1);
    for (int i = v.size() - 1; i >= 0;)
    {
        maximum = max(maximum, v[i]);
        if (v[i] > st.top())
        {
            ans[i] = st1.top();
            st.push(v[i]);
            st1.push(i);
            i--;
        }
        else
        {
            st.pop();
            st1.pop();
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == -1)
            ans[i] = v.size();
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> v)
{

    // broth force
    vector<int> ans(v.size());

    // using stack
    stack<int> st;
    stack<int> st1;
    st.push(-1);
    st1.push(-1);
    for (int i = 0; i < v.size();)
    {
        if (v[i] > st.top())
        {
            ans[i] = st1.top();
            st.push(v[i]);
            st1.push(i);
            i++;
        }
        else
        {
            st.pop();
            st1.pop();
        }
    }

    return ans;
}

int largest_rectangle(vector<int> v)
{
    vector<int> temp1 = nextSmallerElement(v);
    vector<int> temp2 = prevSmallerElement(v);
    int maximum = -1;
    for (int i = 0; i < temp1.size(); i++)
    {
        int area = (temp1[i] - temp2[i] - 1) * v[i];
        maximum = max(area, maximum);
    }
    return maximum;
}

int main()
{

    vector<int> s1 = {2, 4};
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
    cout << endl;
    cout << largest_rectangle(s1);
}
