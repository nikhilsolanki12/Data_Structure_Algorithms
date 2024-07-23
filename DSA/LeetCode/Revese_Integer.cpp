#include <iostream>

using namespace std;

int reverse(int x)
{
}
int main()
{
    int x = 0, d = 1, m = -234, sum = 0;
    // cout << m * (-1);
    if (m < 0)
    {
        x = 1;
        m = m * (-1);
        cout << m;
    }
    else
        x = 0;

    for (int n = m; n > 0; n = n / 10, d = d * 10)
        ;
    d = d / 10;

    while (m > 0)
    {
        int r = m % 10;
        sum = sum + r * d;
        d = d / 10;
        m = m / 10;
    }
    if (x == -1)
        sum = -(sum);

       return 0;
}