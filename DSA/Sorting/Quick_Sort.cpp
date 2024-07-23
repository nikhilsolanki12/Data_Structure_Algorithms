#include <iostream>

using namespace std;

int partition(int arr[], int s, int e)
{
    int pivotIndex = s;
    int pivotElement = arr[s];

    int count = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivotElement)
            count++;
    }

    // jab me loop se bahar aaya to pivot element ko rigthposition pr swap krna hain

    int rightPosition = s + count;
    swap(arr[pivotIndex], arr[rightPosition]);
    pivotIndex = rightPosition;

    // step 3: left me chhote or right me bade

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement)
        {
            i++;
        }
        while (arr[j] > pivotElement)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i], arr[j]);
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;

    // partition case  return pivot element
    int p = partition(arr, s, e);
    // recursion case

    // pivot element->left
    quickSort(arr, s, p - 1);

    // pivot element->Right
    quickSort(arr, p + 1, e);
}

int main()
{
    // int arr[] = {8, 4, 6, 20, 1, 1, 1, 1, 1, 2, 22, 2, 2, 2, 20, 50, 30, 20};
    int arr[] = {8, 1, 3, 4, 20, 50, 50, 50, 50, 50, 5, 1, 1, 1, 1, 2, 2, 2, 50, 30};
    int n = 20;
    int s = 0, e = n - 1;

    quickSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }

    return 0;
}