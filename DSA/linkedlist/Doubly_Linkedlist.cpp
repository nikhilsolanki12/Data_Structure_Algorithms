#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(/* args */)
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void InsertatHead(Node *&head, Node *&tail, int data)
{
    Node *tmp = new Node(data);
    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }
}

void InsertatTail(Node *&head, Node *&tail, int data)
{
    Node *tmp = new Node(data);
    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << " " << head->data;
        head = head->next;
    }
}
void displayRev(Node *tail)
{
    while (tail != NULL)
    {
        cout << " " << tail->data;
        tail = tail->prev;
    }
}
int getlength(Node *head)
{
    int cnt = 0;
    if (head == NULL)
        return 0;
    else
    {

        while (head != NULL)
        {
            head = head->next;
            cnt++;
        }
    }
    return cnt;
}
void InsertAtPos(Node *&head, Node *&tail, int pos, int data)
{
    if (head == NULL)
    {
        cout << "Linked List Is Empty";
        return;
    }
    if (pos == 1)
    {
        InsertatHead(head, tail, data);
        return;
    }
    if (pos - 1 == getlength(head))
    {
        InsertatTail(head, tail, data);
        return;
    }
    Node *cur = head;
    Node *prv = head;
    while (pos != 1 && cur->next != NULL)
    {
        prv = cur;
        cur = cur->next;
        pos--;
    }
    Node *newNode = new Node(data);
    newNode->next = cur;
    cur->prev = newNode;
    newNode->prev = prv;
    prv->next = newNode;
}

void DeleteAtPos(Node *&head, Node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "Linked List Is Empty";
        return;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    if (pos == getlength(head))
    {
        Node *temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }
    Node *cur = head;
    Node *prv = head;
    while (pos != 1 && cur->next != NULL)
    {
        prv = cur;
        cur = cur->next;
        pos--;
    }
    prv->next = cur->next;
    cur->next->prev = prv;
    delete cur;
}
int main()
{
    Node *head = new Node(10);
    Node *tail = head;
    InsertatHead(head, tail, 19);
    InsertatHead(head, tail, 11);
    InsertatHead(head, tail, 12);
    InsertatHead(head, tail, 13);
    InsertatHead(head, tail, 86);
    InsertatTail(head, tail, 1);
    InsertAtPos(head, tail, 7, 99);
    display(head);
    cout << endl;
    DeleteAtPos(head, tail, 1);
    DeleteAtPos(head, tail, getlength(head));
    display(head);
    DeleteAtPos(head, tail, 1);
    cout << endl;
    display(head);

    // displayRev(tail);
}
