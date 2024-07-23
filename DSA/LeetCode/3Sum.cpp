#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int sum = -1;
    int i = 0, j = i + 1, k = j + 1;

    vector<vector<int>> ans;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = 0; j < nums.size() && j != i; j++)
    //     {
    //         for (int k = 0; k < nums.size() && k != i && k != j; k++)
    //         {
    //             sum = nums[i] + nums[j] + nums[k];
    //             if (sum == 0)
    //             {
    //                 vector<int> arr;
    //                 arr.push_back(nums[i]);
    //                 arr.push_back(nums[j]);
    //                 arr.push_back(nums[k]);
    //                 sort(arr.begin(), arr.end());

    //             }
    //         }
    //     }
    //     sort(ans.begin(), ans.end());
    // }

    while (i < nums.size())
    {
        // int tar = -nums[i];
        while (k < nums.size())
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                vector<int> arr;
                arr.push_back(nums[i]);
                arr.push_back(nums[j]);
                arr.push_back(nums[k]);
                sort(arr.begin(), arr.end());
                auto it = find(ans.begin(), ans.end(), arr);
                if (it == ans.end())
                {
                    ans.push_back(arr);
                }
            }
            k++;
        }
        if (j == nums.size())
        {
            i = i + 1;
            j = i + 1;
            k = j + 1;
        }

        else if (j < nums.size())
        {
            j++;
            k = j + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> Sum_3{1, 2, 3, -1, 0, -1, 2};
    vector<vector<int>> answer;
    set<vector<int>> s1;

    s1.insert({3, 4, 5});
    // answer.push_back(s1[i]);

    // answer = threeSum(Sum_3);
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);

    // cout
    //     << answer.size();
    return 0;
}