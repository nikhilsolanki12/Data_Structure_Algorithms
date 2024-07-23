#include <iostream>
using namespace std;
int main()
{
    int arr[1000];
    for (int i = 0; i < 99; i++)
    {
        arr[i] = 100 + rand() % 900;
    }
    cout << "Original array : " << endl
         << endl;
    for (int i = 0; i < 99; i++)
    {
        cout << arr[i] << " ";
    }
    int arr2[1000];
    int j = 0;
    for (int i = 0; i < 99; i++)
    {
        if (arr[i] % 3 == 0 || arr[i] % 5 == 0 || arr[i] % 7 == 0)
        {
            arr2[j] = arr[i];
            j++;
        }
    }
    for (int i = 1; i < j; i++)
    {
        int k = i - 1;
        int temp = arr2[i];
        for (; k >= 0; k--)
        {
            if (arr2[k] > temp)
            {
                arr2[k + 1] = arr2[k];
            }
            else
            {
                break;
            }
        }
        arr2[k + 1] = temp;
    }
    int m = 0;
    for (int i = 0; i < 99; i++)
    {
        if (arr[i] % 3 == 0 || arr[i] % 5 == 0 || arr[i] % 7 == 0)
        {
            arr[i] = arr2[m];
            m++;
        }
    }
    cout << endl
         << endl
         << endl
         << "Sorted Array : " << endl
         << endl;
    for (int i = 0; i < 99; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}