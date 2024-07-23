#include <queue>
#include <iostream>
#include <stack>

using namespace std;

void interLeave(queue<int> &q)
{
    queue<int> st;
    int n = q.size();
    int temp = n / 2;

    while (temp != 0)
    {
        st.push(q.front());
        q.pop();
        temp--;
    }

    while (!st.empty())
    {
        int first = st.front();
        st.pop();
        q.push(first);
        int second = q.front();
        q.pop();
        q.push(second);
    }

    if (n & 1) // modulus take longer time
    {
        int first = q.front();
        q.pop();
        q.push(first);
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
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    print(q);
    interLeave(q);
    print(q);

    return 0;
}