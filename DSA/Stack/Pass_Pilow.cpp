#include <iostream>

using namespace std;
int passThePillow(int n, int time)
{
    int cnt = 1;
    int j = 1;
    for (int i = 1; i <= time; i++)
    {
        cnt = cnt + j;

        if (cnt == n)
            j = -1;
        if (cnt == 1)
            j = 1;
    }
    cout << endl;
    return cnt;
}
int main()
{
    int n = 4, time = 5;
    cout << passThePillow(4, 5);
    cout << passThePillow(2, 5);
    cout << passThePillow(3, 2);
    cout << passThePillow(1000, 50);
    cout << passThePillow(40, 1000);
}