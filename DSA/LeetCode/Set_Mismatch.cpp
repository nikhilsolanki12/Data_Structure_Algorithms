#include <iostream>
#include <vector>

using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
    int dup = -1, mul = -1;
    for (int x : nums)
    {
        if (nums[abs(x) - 1] < 0)
            dup = x;
        else
            nums[abs(x - 1)] *= -1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            return {dup, i + 1};
    }
    return {};
}

int main()
{
    vector<int> v1{1, 2, 2, 4, 5};

    vector<int> s1 = findErrorNums(v1);
    for (int i = 0; i < s1.size(); i++)
    {
        cout << s1[i] << " ";
        // cout << ":";
    }
    return 0;
}