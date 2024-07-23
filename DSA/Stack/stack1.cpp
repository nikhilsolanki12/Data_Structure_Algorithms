#include <iostream>

using namespace std;

class NODE
{
public:
    int data;
    NODE *left;
    NODE *right;
    NODE(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

NODE *builttree(NODE *&root)
{
    cout << "enter the data" << endl;
    int data;
    cin >> data;
    root = new NODE(data);

    if (data == -1)
    {
        return NULL;
    }
    else
    {
        cout << "enter the value of left sub tree" << endl;
        root->left = builttree(root->left);
        cout << "enter the value of right sub tree" << endl;
        root->right = builttree(root->right);
    }
}
int main()
{

    NODE *root = NULL;
    root = builttree(root);
    return 0;
}