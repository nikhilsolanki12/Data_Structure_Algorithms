#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findClosestElement(vector<int> &nums, int x, int k)
{
    vector<int> ans;
    vector<int> arr;

    // Bruth Force
    //..............
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     arr.push_back(abs(x - nums[i]));
    // }
    // int i = 0;
    // while (k > 0)
    // {
    //     for (int j = 0; j < arr.size(); j++)
    //     {
    //         if (arr[j] == i)
    //         {
    //             ans.push_back(nums[j]);
    //             k--;
    //         }
    //         if (k == 0)
    //             break;
    //     }
    //     i++;
    // }

    int l = 0, h = nums.size() - 1;
    while ((h - l) >= k)
    {
        if (abs((x - nums[l])) > abs((x - nums[h])))
            l++;
        else
            h--;
    }
    for (int i = l; i <= h; i++)
    {
        ans.push_back(nums[i]);
    }
    return ans;
}

int main()
{
    vector<int> nums{1, 2, 3, 4};
    int x = 3, k = 4;
    vector<int> ans;
    ans = findClosestElement(nums, x, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    return 0;
}
