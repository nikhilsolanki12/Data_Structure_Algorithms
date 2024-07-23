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
Node *reverseLL(Node *head)
{
    Node *prv = NULL;
    Node *cur = head;
    Node *forward = cur->next;
    while (cur != NULL)
    {
        forward = cur->next;
        cur->next = prv;
        prv = cur;
        cur = forward;
    }
    return prv;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *Sum2LL(Node *LL1, Node *LL2)
{

    LL1 = reverseLL(LL1);
    LL2 = reverseLL(LL2);
    int sum = 0, carry = 0;
    Node *newHead = NULL;
    Node *newTail = NULL;

    while (LL1 != NULL && LL2 != NULL)
    {
        sum = carry + LL1->data + LL2->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);

        if (newHead == NULL)
        {
            newHead = newNode;
            newTail = newNode;
        }
        else
        {
            newTail->next = newNode;
            newTail = newNode;
        }
        LL1 = LL1->next;
        LL2 = LL2->next;
    }

    sum = 0;

    while (LL1 != NULL)
    {
        sum = carry + LL1->data;
        int digits = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digits);
        newTail->next = newNode;
        newTail = newNode;
        LL1 = LL1->next;
    }

    while (LL2 != NULL)
    {
        sum = carry + LL2->data;
        int digits = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digits);
        newTail->next = newNode;
        newTail = newNode;
        LL2 = LL2->next;
    }

    while (carry != 0)
    {
        sum = carry;
        int digits = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digits);
        newTail->next = newNode;
        newTail = newNode;
    }
    newHead = reverseLL(newHead);
    return newHead;
}

int main()
{
    Node *head = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(4);
    Node *node6 = new Node(4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    Node *head1 = new Node(1);
    Node *node11 = new Node(2);
    Node *node12 = new Node(2);
    Node *node13 = new Node(3);
    Node *node14 = new Node(4);
    Node *node15 = new Node(4);
    Node *node16 = new Node(7);

    head1->next = node11;
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    // node15->next = node16;

    printLL(head);
    cout << endl;
    printLL(head1);
    cout << endl;

    head = Sum2LL(head, head1);
    cout << endl;
    printLL(head);
    cout << endl;

    return 0;
}