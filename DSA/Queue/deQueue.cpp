#include <iostream>

using namespace std;

class dequeue
{
public:
    int size;
    int *arr;
    int front;
    int rear;

    dequeue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push_front(int data)
    {
        if (rear == size - 1 && front == 0 || rear == front - 1)
        {
            cout << "overflow";
            return;
        }
        else if (front == -1)
        {
            rear = 0;
            front = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }

    void pop_front()
    {
        if (front == -1)
        {
            cout << "underflow";
            return;
        }
        else if (front == rear)
        {

            front = -1;
            rear = -1;
        }
        else if (front = size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void push_Rear(int data)
    {
        if (rear == size - 1 && front == 0 || rear == front - 1)
        {
            cout << "overflow";
            return;
        }
        else if (front == -1)
        {
            rear = 0;
            front = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pop_Rear()
    {
        if (front == -1)
        {
            cout << "underflow";
            return;
        }
        else if (front == rear)
        {

            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }
};

int main()
{

    dequeue dq(5);

    dq.push_front(10);
    dq.push_front(11);
    dq.push_front(11);
    dq.push_Rear(12);

    dq.pop_front();
    cout << dq.front << endl;
    dq.pop_front();
    cout << dq.front << endl;
    dq.pop_front();
    cout << dq.front << endl;
    dq.pop_front();
    cout << dq.front << endl;
    // cout << dq.front;
}