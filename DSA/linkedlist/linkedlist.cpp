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

void insertathead(NODE *&head, int d)
{
    NODE *temp = new NODE(d);
    temp->next = head;
    head = temp;
}

void display(NODE *&head)
{
    NODE *temp;
    // temp=head;
    head = temp;
    while (temp != 0)
    {
        cout << temp->data << "->";
        // temp->next = temp;
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    int d;
    NODE *node1 = new NODE(10);
    NODE *head = node1;
    // cout << node1->data;
    insertathead(head, 20);
    insertathead(head, 30);
    insertathead(head, 40);
    insertathead(head, 50);
    insertathead(head, 60);
    display(head);

    return 0;
}