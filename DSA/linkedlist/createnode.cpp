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

int main()
{
    NODE *node1 = new NODE(10);
    NODE *node2 = new NODE(5);
    cout << node1->data << endl;
    cout << node2->data << endl;

    return 0;
}