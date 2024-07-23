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

int getLength(Node *head)
{
    Node *temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
Node *getMiddle(Node *head)
{
    Node *temp = head;
    int len = getLength(temp) / 2;
    while (len != 0)
    {
        temp = temp->next;
        len--;
    }
    return temp;
}

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
bool ckeckPalindrome(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *middle = getMiddle(head);
    Node *reverseLLhead = reverseLL(middle->next);
    middle->next = reverseLLhead;
    Node *temp = head;
    Node *temp1 = reverseLLhead; // doubt

    while (temp1 != NULL)
    {
        if (temp->data != temp1->data)
            return false;

        temp = temp->next;
        temp1 = temp1->next;
    }
    return true;
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

void removeDuplicate(Node *&head)
{
    Node *prv = head;
    Node *curr = head->next;

    while (curr != NULL)
    {
        if (prv->data == curr->data)
        {
            prv->next = curr->next;
            curr = curr->next;
        }
        else
        {
            prv = prv->next;
            curr = curr->next;
        }
    }
}
int main()
{
    Node *head = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // printLL(head);

    // if (ckeckPalindrome(head))
    // {
    //     cout << "Palindrome";
    // }
    // else
    //     cout << "not palindrome";
    // return 0;

    // remove duplicate from sorted LL

    removeDuplicate(head);
    printLL(head);
}