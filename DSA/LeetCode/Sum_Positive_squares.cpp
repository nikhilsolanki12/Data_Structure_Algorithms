#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int sumSquare(int n, int result, int current_test)
{

    if (current_test == n)
        return result;

    int j;
    cout << "Enter the number : ";
    cin >> j;
    if (j > 0)
    {
        result = result + pow(j, 2);
    }
    return sumSquare(n, result, current_test + 1);
}
int main()
{

    int n = 5;
    int result = 0;
    int current_test = 0;
    int k = sumSquare(n, result, current_test);
    cout << k;

    return 0;
}