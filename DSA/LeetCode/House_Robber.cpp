#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int rob(vector<int> &v1)
{
    vector<int> p;

    p.push_back(v1[0]);
    if (v1.size() > 1)
        p.push_back(max(v1[0], v1[1]));

    for (int i = 2; i < v1.size(); i++)
    {
        p.push_back(max(p[i - 1], p[i - 2] + v1[i]));
    }
    return p[p.size() - 1];
}
int main()
{
    vector<int> v1{1, 3, 1, 4, 5};

    cout << "Max Money : " << rob(v1);
    return 0;
}
