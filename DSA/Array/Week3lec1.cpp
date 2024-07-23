#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 9;

    int start = 0, end = size - 1;

    // First and last print krna continue
    // while (start <= end)
    // {
    //     if (start == end)
    //     {
    //         cout << arr[start];
    //         break;
    //     }
    //     cout << arr[start];
    //     cout << arr[end] << endl;
    //     start++;
    //     end--;
    // }

    // Reverse the array
    int tmp;
    while (start < end)
    {
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}