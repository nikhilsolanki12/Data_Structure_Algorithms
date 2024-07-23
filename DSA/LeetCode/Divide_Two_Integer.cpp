
#include <iostream>
// #include<climits>
#include <math.h>
using namespace std;

int main()
{
    long int dividend = -2147483648;
    long int division = -1;

    long double ans;
    int a = pow(2, 31) - 1;
    int b = -pow(2, 31);
    cout << a << endl;
    cout << b << endl;
    if (dividend > a)
        dividend = a;
    else if (dividend <= b)
        dividend = b - 1;
    cout << dividend << endl;
    ans = (double)dividend / (double)division;

    cout << (float)ans << endl;

    cout << (long int)ans << endl;

    return 0;
}