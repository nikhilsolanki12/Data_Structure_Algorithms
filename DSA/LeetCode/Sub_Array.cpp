#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1{11, 81, 94, 43, 3};
    int ans = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = i; j < v1.size(); j++)
        {
            int min = v1[j];
            for (int k = i; k <= j; k++)
            {
                if (min > v1[k])
                {
                    min = v1[k];
                }
            }
            cout << min;
            ans = ans + min;
            cout << endl;
        }
    }
    cout << ans;
}