#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    vector<int> ans;
    set<int> temp;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)
            {
                temp.insert(nums[i]);
                temp.insert(nums[j]);
            }
        }
    }
    for (auto it = temp.begin(); it != temp.end(); ++it)
        cout << ' ' << *it;
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 130, 8, 9, 10, 135, 12, 140, 14, 15, 16, 145, 18, 20, 21, 22, 150, 24, 25, 26, 27, 28, 155, 30, 32, 33, 34, 35, 36, 38, 39, 40, 42, 44, 45, 46, 48, 50, 51, 52, 54, 55, 56, 57, 58, 60, 62, 63, 65, 66, 69, 70, 72, 75, 78, 80, 81, 84, 85, 87, 90, 93, 95, 100, 105, 110, 115, 120, 125};
    vector<int> ans;

    sort(nums.begin(), nums.end());
    ans.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < ans.size(); j++)
        {
            if (nums[i] % ans[j] == 0 || ans[j] % nums[i] == 0)
            {
                cnt++;
            }
        }
        if (cnt == ans.size())
            ans.push_back(nums[i]);
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}