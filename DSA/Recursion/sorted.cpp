#include <iostream>
#include <vector>

using namespace std;

bool sorted(vector<int> nums, int i)
{
    if (i == nums.size() - 1)
        return true;
    if (nums[i] >= nums[i + 1])
        return false;

    return sorted(nums, i + 1);
}

int main()
{
    vector<int> nums{2, 6, 8, 9, 2};

    bool ans = sorted(nums, 0);
    if (ans)
        cout << "Array is sorted...";
    else
        cout << "Array is not sorted...";
    return 0;
}