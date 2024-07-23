#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *array;

    Stack(int size)
    {
        this->size = size;
        this->array = new int[size];
        top = -1;
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack underflow";
        }
    }
    void push(int a)
    {
        if (size - top > 1)
        {
            top++;
            array[top] = a;
        }
        else
        {
            cout << "stack overflow";
        }
    }

    void peak()
    {
        if (top >= 0)
        {
            cout << array[top];
        }
        else
        {
            cout << "stack is empty";
        }
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s(12);
    Stack n(12);
    s.push(17);
    s.push(12);
    // n = s;
    s = n;
    n.peak();
    cout << s.size;

    return 0;
}