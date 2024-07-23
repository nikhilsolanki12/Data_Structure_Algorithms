#include <iostream>

using namespace std;

class Stack
{
public:
    int size;
    int top;
    char *arr;

    Stack(int size)
    {
        this->size = size;
        this->arr = new char[size];
        top = -1;
    }

    void push(auto data)
    {
        if (top == size - 1)
        {
            cout << "stack overflow";
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
            cout << "stack underflow";
        else
        {
            top--;
        }
    }
    char peak()
    {
        return arr[top];
    }
};

string reverseString(string &s)
{
    string s2 = "";
    Stack s1(s.length());
    char array[s.length()] = {};
    for (int i = 0; i < s.length(); i++)
    {
        s1.push(s[i]);
    }

    int i = 0;
    while (s1.top != -1)
    {
        array[i] = s1.peak();
        s1.pop();
        i++;
    }
    array[i] = '\0';

    s2.append(array);
    return s2;
}
int main()
{
    string s = "asdf";
    Stack s1(s.length());
    for (int i = 0; i < s.length(); i++)
    {
        s1.push(s[i]);
    }

    s = reverseString(s);
    cout << s;
}