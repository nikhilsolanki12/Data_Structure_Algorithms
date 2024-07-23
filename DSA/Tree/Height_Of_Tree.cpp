#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int date)
    {
        this->data = date;
        left = right = NULL;
    }
};

Node *buildTree(int data)
{
    if (data == -1)
        return NULL;

    Node *root = new Node(data);

    cout << "Enter the left node of" << data << " :";
    int leftData;
    cin >> leftData;
    root->left = buildTree(leftData);

    cout << "Enter the right node of" << data << " :";
    int rightData;
    cin >> rightData;
    root->right = buildTree(rightData);

    return root;
}

int Height(Node *root)
{
    if (root == NULL)
        return 0;

    int opt1 = Height(root->left);
    int opt2 = Height(root->right);

    return max(opt1, opt2) + 1;
}

int HeightDiff(Node *root)
{
    int opt1 = Height(root->left);
    int opt2 = Height(root->right);

    return abs(opt1 - opt2);
}
int main()
{
    Node *root = buildTree(5);
    cout << HeightDiff(root);
    S

        return 0;
}