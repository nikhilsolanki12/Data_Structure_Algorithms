#include <iostream>
#include <vector>

using namespace std;

void selection_Sort(vector<int> &arr)
{
    int min;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        min = i;
        // cout << "min : " << min << endl;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        // cout << min << " : " << arr[i] << endl;
        swap(arr[min], arr[i]);
    }
    // return arr;
}

int main()
{
    vector<int> arr{1, 7, 4, 3, 9};
    selection_Sort(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << " " << arr[i];

    return 0;
}
