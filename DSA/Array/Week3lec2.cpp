#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;
    int n, o;
    cout << "enter the size of array : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element of array : ";
        cin >> o;
        arr.push_back(o);
    }
    cout << "Size of vector : " << arr.size() << endl;
    cout << "Capacity of Vector : " << arr.capacity();
    return 0;
}