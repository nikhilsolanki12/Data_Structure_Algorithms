#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> nums, int s, int e, int key)
{
    int mid = s + (e - s) / 2;
    if (nums[mid] == key)
        return mid;
    if (s > e)
        return -1;

    if (nums[mid] >= key)
        return binarySearch(nums, mid, e, key);
    else
        return binarySearch(nums, s, mid - 1, key);
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << binarySearch(nums, 0, nums.size(), 6);
    return 0;
}