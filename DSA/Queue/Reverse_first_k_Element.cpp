#include <queue>
#include <iostream>
#include <stack>

using namespace std;

void reverseQueue(queue<int> &q, int k)
{
    stack<int> st;
    int temp = q.size() - k;
    // if (k > 0)
    // {
    while (k > 0)
    {
        st.push(q.front());
        q.pop();
        k--;
    }

    // cout << st.top();

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    while (temp > 0 && temp < q.size())
    {
        int t = q.front();
        q.push(t);
        q.pop();
        temp--;
    }
    // }
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
    q.push(3);
    q.push(4);
    q.push(4);
    q.push(4);
    print(q);
    reverseQueue(q, 9);
    print(q);

    return 0;
}