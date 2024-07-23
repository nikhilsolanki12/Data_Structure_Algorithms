#include <iostream>
#include <stack>

using namespace std;

// int middleElement(stack<int> s)
// {
//     int i = s.size() / 2;
//     while (i != 0)
//     {
//         s.pop();
//         i--;
//     }
//     return s.top();
// }
void middleElement(stack<int> &s, int &total_size)
{

    if (s.size() == total_size / 2)
    {
        cout << s.top();
        return;
    }

    int temp = s.top();
    s.pop();
    middleElement(s, total_size);
    s.push(temp);
}
int main()
{

    stack<int> s;
    stack<int> s1;

    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(17);
    s.push(18);
    int size = 6;

    middleElement(s, size);
    cout << s.top();

    return 0;
}