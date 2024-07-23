// You are given an array nums consisting of positive integers.

// Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

// The frequency of an element is the number of occurrences of that element in the array.

// Example 1:

// Input: nums = [1,2,2,3,1,4]
// Output: 4
// Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
// So the number of elements in the array with maximum frequency is 4.

#include <iostream>
#include <vector>
#include <algorithm>
// #include "algo.h"

using namespace std;

int maxFrequencyElement(vector<int> &nums)
{
    vector<int> frq;
    int cnt = 0, max = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0, prv = -1; i < nums.size(); i++)
    {
        cnt = 0;
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[i] == prv)
                break;
            else if (nums[i] == nums[j])
            {
                cnt++;
            }
            if (max < cnt)
                max = cnt;
        }
        frq.push_back(cnt);
        prv = nums[i];
    }
    cnt = 0;
    cout << max;
    for (int i = 0; i < frq.size(); i++)
    {
        cout << frq[i];
        if (max == frq[i])
            cnt++;
    }
    // if (cnt == 1)
    //     return nums.size();
    return cnt * max;
}

int main()
{

    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
    int answer = maxFrequencyElement(v1);

    cout << "Maximum frequency element  : " << answer;
    return 0;
}
