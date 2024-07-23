#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> test{3, 2, 3};
    int ans;
    int count = 1;
    int temp = test[0];
    int length = test.size();
    sort(test.begin(), test.end());
    for (int i = 1; i < length; i++)
    {
        if (temp == test[i])
        {
            count++;
            if (count > length / 2)
            {
                cout << test[i];
                break;
            }
        }
        else
        {
            temp = test[i];
            count = 1;
        }
    }
    return 0;
}