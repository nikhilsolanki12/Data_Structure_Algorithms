#include <iostream>
#include <vector>

using namespace std;

void bubble_Sort(vector<int> &arr)
{
    int min;

    for (int i = arr.size() - 1; i > 0; i--)
    {
        bool swapped = false;
        for (int j = arr.size() - i; j > 0; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                // swapped = true;
            }
        }
        // if (swapped == false) // already sorted
        //     break;
    }
}

int main()
{
    vector<int> arr{8, 4, 7, 254, 67, 34};
    bubble_Sort(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << " " << arr[i];

    return 0;
}
