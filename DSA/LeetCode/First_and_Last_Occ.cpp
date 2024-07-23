#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int firstOccurance(vector<int> arr, int key)
{
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > key)
            e = mid - 1;
        else if (arr[mid] < key)
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOccurance(vector<int> arr, int key)
{
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > key)
            e = mid - 1;
        else if (arr[mid] < key)
            s = mid + 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> v1{1, 2, 3, 3, 4, 5, 6, 7, 8, 3};
    sort(v1.begin(), v1.end());

    cout << "First Occurance of 3 is :" << firstOccurance(v1, 10) << endl;
    cout << "First Occurance of 3 is :" << lastOccurance(v1, 3) << endl;

    cout << "Total No. of Element : " << lastOccurance(v1, 3) - firstOccurance(v1, 3) + 1;

    return 0;
}