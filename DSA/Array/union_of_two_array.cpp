#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array1 : ";
    cin >> n;

    vector<int> arr1;
    for (int i = 0, s = 0; i < n; i++)
    {
        cout << "Enter the element of array1 : ";
        cin >> s;
        arr1.push_back(s);
    }

    cout << "Enter the size of array2 : ";
    cin >> n;

    vector<int> arr2;
    for (int i = 0, s = 0; i < n; i++)
    {
        cout << "Enter the element of array2 : ";
        cin >> s;
        arr2.push_back(s);
    }

    vector<int> arr3;

    return 0;
}