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

void InsertAtNode(NODE *&head, int d)
{
    NODE *temp = new NODE(d);
    temp->next = head;
    head = temp;
}
void print(NODE *&head)
{
    NODE *temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    int data;
    NODE *node1 = new NODE(10);
    cout << node1->data << endl;

    NODE *head = node1;
    InsertAtNode(head, 40);
    InsertAtNode(head, 13);
    print(head);

    return 0;
}