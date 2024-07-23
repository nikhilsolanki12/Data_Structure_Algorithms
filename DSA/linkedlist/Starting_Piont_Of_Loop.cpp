#include <iostream>
#include <vector>
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
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Node *reverseKNode(Node *head, int k)
{

    if (head == NULL || head->next == NULL)
        return head;

    if (k > getLength(head))
        return head;

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    int count = 0;
    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if (forward != NULL)
    {
        head->next = reverseKNode(forward, k);
    }
    return prev;
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

int findFirst(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL || fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;

        if (slow == fast)
        {
            slow = head;
            break;
        }
    }

    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow->data;
}
int main()
{
    Node *n1 = new Node(12);
    Node *n2 = new Node(13);
    Node *n3 = new Node(14);
    Node *n4 = new Node(15);
    Node *n5 = new Node(16);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;

    // print(n1);
    // cout << endl;
    // n1 = reverseKNode(n1, 2);
    // print(n1);
    cout << endl;
    cout << findFirst(n1);
    return 0;
}
