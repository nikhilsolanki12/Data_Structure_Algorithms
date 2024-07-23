#include <iostream>
#include <vector>

using namespace std;

long long minimumOperations(vector<int> &nums, vector<int> &target)
{
    long long int count = 0;
    vector<int> store;

    for (int i = 0; i < nums.size(); i++)
    {
        store.push_back(target[i] - nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << " " << store[i];
    }

    return count;
}

int main()
{
    vector<int> nums = {3, 5, 1, 2};
    vector<int> target = {4, 6, 2, 4};
    long long int count = 0;
    vector<int> store;
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        store.push_back(target[i] - nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << " " << store[i]; //[1,1,1,2]
    }

    for (int i = 0; i < store.size(); i++)
    {
        int ch = store[i];
        while (ch <= 0)
        {
        }
    }
}