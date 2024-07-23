#include <iostream>
#include <vector>
#include <set>

using namespace std;
set<vector<int>> s1;
vector<vector<int>> ans;
void permute(vector<int> &arr, int index)
{
    if (index == arr.size())
    {
        s1.insert(arr);
        return;
    }

    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[i], arr[index]);
        permute(arr, index + 1);
        swap(arr[i], arr[index]);
    }
}

vector<vector<int>> permutations(vector<int> &arr)
{
    permute(arr, 0);

    for (auto i : s1)
    {
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    vector<int> nums{1, 1, 3, 2, 1};
    vector<vector<int>> ans;
    ans = permutations(nums);

    for (auto i : ans)
    {
        for (int j : i)
        {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}