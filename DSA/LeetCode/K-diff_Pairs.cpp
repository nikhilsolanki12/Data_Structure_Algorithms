#include <vector>
#include <iostream>
#include <set>
using namespace std;

int findPairs(vector<int> &nums, int k)
{

    int pairs = 0;
    set<pair<int, int>> s1;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (abs(nums[i] - nums[j]) == k)
            {
                s1.insert({nums[i], nums[j]});
            }
        }
    }

    return s1.size();
}

int main()
{
    // vector<int> nums{3, 1, 4, 5, 1};
    // int k = 2;
    // vector<int> nums{1, 1, 1, 1, 1};
    // int k = 0;
    // vector<int> nums{1, 3, 1, 5, 4};
    // int k = 0;
    vector<int> nums{1, 2, 3, 4, 5};
    int k = 1;
    cout << "No of pair is : " << findPairs(nums, k);
}