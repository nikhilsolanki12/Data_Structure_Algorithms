// find unique element when every element repeat twice except only one
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{2, 4, 6, 8, 10, 10, 6, 8, 3, 6, 2};
    int ans = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        ans = ans ^ arr[i];
    }
    cout << "Unique element is : " << ans;

    return 0;
}
