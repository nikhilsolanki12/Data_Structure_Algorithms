#include <iostream>
#include <vector>

using namespace std;

void insertion_Sort(vector<int> &arr)
{

    // for (int i = 1; i < arr.size(); i++)
    // {
    //     int temp = arr[i];
    //     int j = i - 1;
    //     for (; j >= 0; j--)
    //     {
    //         if (arr[j] > temp)
    //         {
    //             arr[j + 1] = arr[j]; // shift
    //         }
    //         else
    //             break;
    //     }
    //     arr[j + 1] = temp;
    // }

    int i = 1;
    while (i < arr.size())
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
                break;
            j--;
        }
        arr[j + 1] = temp;
        i++;
    }
}

int main()
{

    vector<int> arr{9, 8, 7, 6, 5, 4, 3, 2, 1};

    insertion_Sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}