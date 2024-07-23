#include <iostream>
using namespace std;

int Binary_Search(int arr[], int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] == key)
        {
            return mid + 1;
        }
        if (arr[mid] > key)
        {
            s = mid + 1;
        }
        else
            e = mid - 1;

        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    int *arr;
    int key, n;

    cout << "Enetr the size of array : ";
    cin >> n;
    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element of array : ";
        cin >> arr[i];
    }
    cout << "Enter the Searching element : ";
    cin >> key;
    cout << "\n"
         << Binary_Search(arr, n, key);
    return 0;
}