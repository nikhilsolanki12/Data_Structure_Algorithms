#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    string str1 = "ez";
    string str2 = "e";
    vector<int> intersection;
    int maximum = 0, count = 0, n1, n2;
    if (str1.length() > str2.length())
    {
        n1 = str2.length();
        n2 = str1.length();
    }
    else
    {
        n2 = str2.length();
        n1 = str1.length();
    }
    for (int i = 0; i <= n2; i++)
    {
        for (int j = 0; j <= n1; j++)
        {
            if (str1[i] == str2[j])
            {
                intersection.push_back(j);
            }
        }
    }
    if (intersection.size() <= 2)
        cout << intersection.size() - 1;
    for (int j = 0; j < intersection.size() - 2; j++)
    {
        if (intersection[j] < intersection[j + 1])
        {
            count++;
            // cout << count << endl;
            maximum = max(maximum, count + 1);
        }
        else
        {

            count = 0;
        }
    }
    cout << endl;
    cout << maximum;

    return 0;
}