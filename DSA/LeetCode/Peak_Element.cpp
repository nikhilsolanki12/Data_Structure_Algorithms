#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    vector<int> v1{3, 2, 1, 4};
    // int max = v1[0];
    int n = v1.size();
    vector<int> minPrefix(n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int minValue = v1[i];
        if (i > 0)
        {
            minValue = std::min(minValue, minPrefix[i - 1]);
        }
        minPrefix[i] = minValue;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            ans += minPrefix[j];
        }
    }
    cout << ans;
}
