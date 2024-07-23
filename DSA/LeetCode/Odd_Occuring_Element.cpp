/*
find the odd Occurring element in array ?

->All the repeating occurrence of element appear in pairs
-> pairs are not adjacent
-> find the element appears odd time

*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr{1, 1, 2, 2, 676, 676, 2, 2, 90, 3, 3, 5, 5};

    //    Using linear Search
    //    ...................

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == arr[i + 1])
        {
            i = i + 1;
        }
        else
        {
            cout << arr[i] << endl;
            break;
        }
    }

    //      Using XOR
    //     ..........

    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
        ans = ans ^ arr[i];
    cout << "Using XOR : " << ans << endl;

    // Using index observation
    //.......................

    for (int i = 0; i < arr.size(); i = i + 2)
        if (arr[i] != arr[i + 1])
        {
            cout << "Using index observation : " << arr[i] << endl;
            break;
        }

    // Using Binary Search
    //....................

    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (s == e)
        {
            cout << "Using Binary Search : " << arr[mid];
            break;
        }

        // -> case 2:- mid-even or mid-odd

        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
                s = mid + 2;
            else
                e = mid;
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
}