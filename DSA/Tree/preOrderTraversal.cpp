#include <iostream>

using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *builtTree(int data)
{
    if (data == -1)
        return NULL;

    Node *root = new Node(data);

    int leftData = 0;
    cout << "Enter the left node of the " << data << " : ";
    cin >> leftData;
    root->left = builtTree(leftData);

    int rightData = 0;
    cout << "Enter the right node of the " << data << " : ";
    cin >> rightData;
    root->right = builtTree(rightData);

    return root;
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
int main()
{
    int rootData = 0;
    cout << "Enter the root element : ";
    cin >> rootData;
    Node *root = builtTree(rootData);
    preOrderTraversal(root);

    return 0;
}