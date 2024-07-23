#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int max_diff = 0;
    int small = prices[0];
    // for (int i = 0; i < prices.size(); i++)
    // {
    //     for (int j = i + 1; j < prices.size(); j++)
    //     {
    //         if (prices[j] > prices[i])
    //             max_diff = max(max_diff, (prices[j] - prices[i]));
    //     }
    // }
    for (int i = 1; i < prices.size(); i++)
    {
        int cost = prices[i] - small;
        max_diff = max(max_diff, cost);
        small = min(small, prices[i]);
    }
    return max_diff;
}

int main()
{
    // vector<int> prices{7, 1, 5, 3, 6, 4};
    vector<int> prices{1, 2, 3, 4, 5, 6, 7};
    // vector<int> prices{9, 8, 7, 6, 5, 4, 3, 2, 1};
    // vector<int> prices{1, 1, 1, 1, 1, 1};

    cout << "Profit " << maxProfit(prices);

    return 0;
}