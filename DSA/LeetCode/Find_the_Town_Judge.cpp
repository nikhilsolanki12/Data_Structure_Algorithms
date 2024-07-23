#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    vector<vector<int>> trust{{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
    set<int> s1, s2;
    set<int> intersection;

    for (int i = 0; i < trust.size(); i++)
    {
        s1.insert(trust[i][0]);
        s2.insert(trust[i][1]);
    }
    set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(),
                   std::inserter(intersection, intersection.begin()));
    int ans = 0;
    if (intersection.size() > 0)
        for (int i : intersection)
            cout << i;
}