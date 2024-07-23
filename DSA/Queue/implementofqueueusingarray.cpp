// Q. Implement of queue using array?

#include <iostream>

using namespace std;

class Queue
{
public:
    int rear;
    int front;
    int *array;
    int size;
    Queue(int size)
    {
        this->size = size;
        array = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    {
        if (size - rear > 1)
        {
            array[rear] = data;
            rear++;
        }
        else
            cout << "Queue overflow";
    }
    void pop()
    {
        if (rear == 0)
        {
            cout << "Queue underflow";
        }
        else
            rear--;
    }

    void top()
    {
        if (rear >= 0)
        {
            cout << "The top element of Queue is: " << array[front];
        }
        else
            cout << "Queue is empty";
    }
};

int main()
{

    int size;
    cout << "Enter the no. of Elelments of Queue:  ";
    cin >> size;
    Queue q1(size);
lable:
    cout << endl;
    cout << endl;
    cout << "Choose the option for the further Operation" << endl;
    cout << "1:push the element in Queue" << endl;
    cout << "2: pop the element in Queue" << endl;
    cout << "3: display top element in Queue" << endl;
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
        q1.push(b);

        break;
    case 2 /* constant-expression */:

        q1.pop();

        break;
    case 3 /* constant-expression */:
        q1.top();

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