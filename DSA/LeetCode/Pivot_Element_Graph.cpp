#include <iostream>
#include <vector>

using namespace std;

int getpivot(vector<int> &arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
            mid = e;

        mid = s + (e - s) / 2;
    }
    return s;
}

int main()
{
    vector<int> arr{7, 9, 1, 2, 3, 7};

    cout << "Pivot : " << getpivot(arr);
}