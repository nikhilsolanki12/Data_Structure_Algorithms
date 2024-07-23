#include <queue>
#include <iostream>
#include <stack>

using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    // cout << st.top();

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
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