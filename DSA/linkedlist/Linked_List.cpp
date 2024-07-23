#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertatHead(Node *&head, Node *&tail, int data)
{

    Node *temp = new Node(data);
    temp->next = head;
    if (head->next == NULL)
        tail = head;
    head = temp;
}

void insertatTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);

    tail->next = temp;
    tail = temp;
}
void display(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << " " << temp->data;
        // head = head->next;
        temp = temp->next;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int data)
{
    if (pos == 1)
    {
        insertatHead(head, tail, data);
        return;
    }
    Node *temp = head;
    while (pos != 1 && temp->next != NULL)
    {
        temp = temp->next;
        pos--;
    }
    if (pos != 1)
    {
        cout << "Position not exist...";
        return;
    }
    else
    {
        Node *td = new Node(data);
        td->next = temp->next;
        temp->next = td;
    }
}

void del(Node *&head, int pos)
{
    Node *cur = head;
    Node *prv;
    while (pos != 0)
    {
        prv = cur;
        cur = cur->next;
        pos--;
        // cout<<cur->data;
    }
    cout << endl;
    cout << "prv : " << prv->data;
    cout << endl;
    cout << "cur : " << cur->data;
    prv->next = cur->next;
    delete (cur);
}
int main()
{
    Node *head = new Node(12);
    Node *tail;
    insertatHead(head, tail, 9);
    // insertatHead(a,8);
    // insertatHead(a,6);
    // insertatHead(a,5);
    insertatTail(head, tail, 10);
    insertatTail(head, tail, 10);
    insertatTail(head, tail, 10);
    insertAtPosition(head, tail, 1, 1);
    display(head);
}