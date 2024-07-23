#include <iostream>

using namespace std;

double myPow(double x, int n)
{
    static long double ans = 1;
    if (n == 0)
        return ans;
    if (n > 0)
    {
        ans = ans * x;
        return myPow(x, n - 1);
    }
    else
    {
        ans = ans / x;
        return myPow(x, n + 1);
    }
}
int main()
{
    int n = 3;
    double x = 2.10000;

    cout << myPow(x, n);

    return 0;
}