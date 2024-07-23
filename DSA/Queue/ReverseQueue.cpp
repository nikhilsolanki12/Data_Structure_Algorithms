#include <queue>
#include <iostream>

using namespace std;

void reverseQueue(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int t = q.front();
    q.pop();
    reverseQueue(q);
    q.push(t);
}

void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    print(q);
    reverseQueue(q);
    print(q);

    return 0;
}