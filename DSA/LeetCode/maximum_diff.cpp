#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// int longestSubarray(vector<int> &nums, int limit)
// {
//     vector<int> temp;
//     int maximum = 0;
//     if (nums.size() <= 1 || (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end())) <= limit)
//         return nums.size();

//     for (int i = 0; i < nums.size() - 1; i++)
//     {

//         for (int j = i; j < nums.size(); j++)
//         {
//             temp.push_back(nums[j]);
//             if ((*max_element(temp.begin(), temp.end()) - *min_element(temp.begin(), temp.end())) <= limit)
//             {
//                 int size = temp.size();
//                 cout << "maximum : " << maximum << " size : " << size << endl;
//                 maximum = max(maximum, size);
//                 for (int k = 0; k < temp.size(); k++)
//                     cout << temp[k];

//                 cout << endl;
//                 cout << " A maximum : " << maximum << " A size : " << size << endl;
//             }
//             else
//             {
//                 temp.clear();
//                 break;
//             }
//             if (j == nums.size() - 1)
//                 i = nums.size();
//         }
//     }
//     return maximum;
// }
class Solution
{
public:
    int longestSubarray(std::vector<int> &nums, int limit)
    {
        std::deque<int> decQ;
        std::deque<int> incQ;
        int ans = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            int num = nums[right];

            while (!decQ.empty() && num > decQ.back())
            {
                decQ.pop_back();
            }
            decQ.push_back(num);

            while (!incQ.empty() && num < incQ.back())
            {
                incQ.pop_back();
            }
            incQ.push_back(num);

            while (decQ.front() - incQ.front() > limit)
            {
                if (decQ.front() == nums[left])
                {
                    decQ.pop_front();
                }
                if (incQ.front() == nums[left])
                {
                    incQ.pop_front();
                }
                ++left;
            }

            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};

int main()
{

    cout << longestSubarray(temp, 10);
}