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

void insertattail(NODE *&tail, int d)
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

void insertatpostion(NODE *&head, int pos, int val)
{
    NODE *node2 = new NODE(val);
    NODE *temp;
    // temp=node2;
    // head = temp;
    temp = head;
    int c = 1;
    for (; c < pos - 1; c++)
    {
        temp = temp->next;
    }

    node2->next = temp->next;
    temp->next = node2;
}

void deleteatposition(NODE *&head, int pos)
{
    NODE *curnt = head;
    NODE *pre = NULL;
    // curnt = head;
    int i = 1;
    while (i <= pos - 1)
    {
        pre = curnt;
        curnt = curnt->next;
        i++;
    }
    // curnt->next = temp->next->next;
    pre->next = curnt->next;
}
int main()
{

    NODE *node1 = new NODE(12);
    NODE *head = node1;
    NODE *tail = node1;
    cout << node1->data;
    insertattail(tail, 19);
    insertattail(tail, 122);
    insertattail(tail, 13);
    insertattail(tail, 49);
    insertattail(tail, 59);
    insertatpostion(head, 2, 3);
    deleteatposition(head, 6);
    print(head);
    return 0;
}