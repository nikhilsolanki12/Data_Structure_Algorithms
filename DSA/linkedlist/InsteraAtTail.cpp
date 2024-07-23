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
void insertatnode(NODE *&head, int d)
{
    NODE *temp = new NODE(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(NODE *&tail, int d)
{
    NODE *temp = new NODE(d);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}
void print(NODE *&head)
{
    NODE *temp;
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
        }
}
int main()
{
    NODE *node1 = new NODE(10);
    NODE *head = node1;
    NODE *tail = node1;

    // insertatnode(head, 80);
    // insertatnode(head, 1);
    insertatnode(head, 8);
    InsertAtTail(tail, 78);
    InsertAtTail(tail, 20);
    InsertAtTail(tail, 90);
    print(head);

    return 0;
}