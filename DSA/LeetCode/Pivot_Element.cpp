/*
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

*/

#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int> &nums)
{
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;

    // while (mid <= e)
    // {
    //     int sum1 = 0, sum2 = 0;
    //     for (int i = 0; i < mid; i++)
    //     {
    //         sum1 = sum1 + nums[i];
    //     }

    //     for (int i = mid + 1; i < e; i++)
    //     {
    //         sum2 = sum2 + nums[i];
    //     }
    //     if (sum1 == sum2)
    //     {
    //         return mid;
    //     }
    //     else if (sum2 != 0 && sum1 > sum2)
    //     {
    //         mid = mid - 1;
    //     }
    //     else if (sum1 < sum2)
    //         mid = mid + 1;
    //     else if (sum2 == 0)
    //         return 0;
    //}
    int s1 = 0;
    int s2 = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (i == nums.size() - 1) /* this condition added */
            return i;

        s1 = 0, s2 = 0; /* make s1 s2 zero inside for loop */

        for (int k = 0; k < i; k++) /* k<i not k<=i */
        {
            s1 += nums[k];
        }
        for (int j = i + 1; j < nums.size(); j++) /* j=i+1 not j=i+2 */
        {
            s2 += nums[j];
        }
        if (s1 == s2)
        {
            return i; // returning the index of pivot element
        }
    }
    return -1;
}
int main()
{
    vector<int> arr{2, 2, -8, 4, 4};

    cout << "Pivot : " << pivotIndex(arr);
}