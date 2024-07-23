#include <iostream>
using namespace std;

class Queue
{
public:
    int size;
    int *array;
    int front, rear;

    Queue(int size)
    {
        this->size = size;
        array = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int a)
    {
        if (rear == size)
        {
            cout << "overflow";
        }
        else
        {
            array[rear] = a;
            rear++;
        }
    }

    void pop()
    {
        if (rear == front)
        {
            cout << "underflow";
        }
        else
        {
            array[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    void getFront()
    {
        if (front == rear)
        {
            cout << "empty queue";
        }
        else
        {
            cout << array[front] << endl;
            ;
        }
    }

    void getSize()
    {
        cout << rear - front;
    }
};

int main()
{

    Queue s(10);
    s.push(10);
    s.push(12);
    s.push(13);
    s.push(13);
    s.pop();
    s.pop();
    s.pop();

    s.getFront();
    s.getSize();

    return 0;
}