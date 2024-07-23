#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *sortLL(Node *head)
{
    Node *temp0 = new Node(-1);
    Node *temp1 = new Node(-1);
    Node *temp2 = new Node(-1);
    Node *temp3 = temp0;
    Node *temp4 = temp1;
    Node *temp5 = temp2;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            temp0->next = temp;
            temp0 = temp;

            // temp0->next = NULL;
        }
        else if (temp->data == 1)
        {
            temp1->next = temp;
            temp1 = temp;

            // temp1->next = NULL;
        }
        else
        {
            temp2->next = temp;
            temp2 = temp;

            // temp2->next = NULL;
        }
        temp = temp->next;
    }

    if (temp4->next)
    {
        temp0->next = temp4->next;
    }
    else
        temp0->next = temp5->next;

    temp4->next = temp5->next;
    temp2->next = NULL;

    return temp3->next;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node(2);
    Node *node1 = new Node(2);
    Node *node2 = new Node(0);
    // Node *node3 = new Node(1);
    // Node *node4 = new Node(0);
    // Node *node5 = new Node(1);

    head->next = node1;
    node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    // node4->next = node5;
    head = sortLL(head);
    print(head);
}