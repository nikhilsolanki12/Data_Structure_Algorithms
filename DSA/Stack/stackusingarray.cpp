#include <iostream>

using namespace std;
class stack
{
public:
    int size;
    int *array;
    int top;
    stack(int size)
    {
        this->size = size;

        this->array = new int[size];
        top = -1;
    }
    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            array[top] = data;
        }
        else
        {
            cout << "Stack overflow";
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow";
        }
        else
            top--;
    }
    void peak()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
        }
        else
            cout << array[top];
    }
};

int main()
{
    int size;
    cout << "Enter the no. of element in stack" << endl;
    cin >> size;
    stack s(size);

lable:
    cout << endl;
    cout << endl;
    cout << "Choose the option for the further Operation" << endl;
    cout << "1:push the element in Stack" << endl;
    cout << "2: pop the element in Stack" << endl;
    cout << "3: display top element in Stack" << endl;
    cout << "4: Exit" << endl;
    int a;
    cin >> a;
    cout << endl;
    cout << endl;
    switch (a)
    {
    case 1 /* constant-expression */:
        cout << "Enter the element" << endl;
        int b;
        cin >> b;
        s.push(b);

        break;
    case 2 /* constant-expression */:

        s.pop();

        break;
    case 3 /* constant-expression */:
        s.peak();

        break;
    case 4:
        goto exit;
    default:
        break;
    }
    goto lable;
exit:
    return 0;
}