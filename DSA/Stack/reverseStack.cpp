#include <iostream>
#include <stack>

using namespace std;

void insertElement(stack<int> &s, int &key)
{
    if (s.empty() == true)
    {
        cout << "element inserted at bottom of the list";
        s.push(key);
        return;
    }
    int temp = s.top();
    s.pop();
    insertElement(s, key);
    s.push(temp);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        cout << "Stack is empty";
        return;
    }
    int target = s.top();
    s.pop();
    reverseStack(s);
    insertElement(s, target);
}
int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    reverseStack(s);
    cout << s.top();

    return 0;
}