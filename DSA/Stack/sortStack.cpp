#include <iostream>
#include <stack>

using namespace std;

void insertSorted(stack<int> &s, int &target)
{

    if (s.empty())
    {
        s.push(target);
        return;
    }

    if (s.top() >= target)
    {
        s.push(target);
        return;
    }
    int topElement = s.top();
    s.pop();
    insertSorted(s, target);
    s.push(topElement);
}

void sortStakc(stack<int> &s)
{
    if (s.empty())
        return;

    int target = s.top();
    s.pop();
    sortStakc(s);
    insertSorted(s, target);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(3);
    s.push(3);
    s.push(10);
    s.push(5);
    s.push(3);
    sortStakc(s);
    cout << s.size();

    while (!s.empty())
    {
        cout << " " << s.top();
        s.pop();
    }

    return 0;
}