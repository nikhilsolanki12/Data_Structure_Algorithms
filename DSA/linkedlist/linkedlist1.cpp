#include <iostream>

using namespace std;

class NODE
{
public:
    int data;
    NODE *next;
    NODE(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void InsertAtNode(NODE *&head, int data)
{
    NODE *temp = new NODE(data);
    temp->next = head;
    head = temp;
    // temp = head;
}
void display(NODE *&head)
{
    NODE *temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
        // temp->next = temp;
    }
}

void InsertAtTail(NODE *&tail, int data)
{
    NODE *temp = new NODE(data);
    tail->next = temp;

    temp->next = NULL;
    tail = temp;
}
void InsertAtMiddle(NODE *&head, int pos, int data)
{
    NODE *temp = new NODE(data);
    NODE *a = head;
    for (int i = 1; i < pos; i++)
    {
        a = a->next;
    }
    temp->next = a->next;
    a->next = temp;
}
int main()
{
    NODE *first = new NODE(10);
    NODE *head;
    NODE *tail;
    tail = first;

    head = first;

    InsertAtNode(head, 20);
    InsertAtNode(head, 209);
    InsertAtNode(head, 199);
    InsertAtTail(tail, 10);
    InsertAtMiddle(head, 3, 2);

    display(head);

    return 0;
}
