#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> v, int k)
{

    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && v[i] >= v[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(v[dq.front()]);

    // baki window ko process krna
    for (int i = k; i < v.size(); i++)
    {
        while (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && v[i] >= v[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(v[dq.front()]);
    }
    return ans;
}

int main()
{

    vector<int> v{3, 1, 2, -1, 4};
    int k = 3;
    vector<int> ans = maxSlidingWindow(v, k);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}