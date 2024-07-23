/*
1043. Partition Array for Maximum Sum
Medium

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1


Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

int f(int i, vector<int> &arr, int &k, int &n, vector<int> &dp)
{
    if (i >= n)
        return 0;
    int len = 0;
    int maxi = INT_MIN;
    int ans = INT_MIN;
    if (dp[i] != -1)
        return dp[i];
    for (int j = i; j < min(i + k, n); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        ans = max(ans, len * maxi + f(j + 1, arr, k, n, dp));
    }
    return dp[i] = ans;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int len = 0;
        int maxi = INT_MIN;
        int ans = INT_MIN;
        for (int j = i; j < min(i + k, n); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            ans = max(ans, len * maxi + dp[j + 1]);
        }
        dp[i] = ans;
    }
    return dp[0];
}
int main()
{
    vector<int> test{1, 15, 7, 9, 2, 5, 10};
    set<int> s1{1, 2, 3, 4, 5};
    // cout<<s1.;
    int k = 3;
    int ans;

    cout << maxSumAfterPartitioning(test, k);

    return 0;
}