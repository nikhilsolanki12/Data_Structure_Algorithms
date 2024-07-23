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

int Height(Node *node)
{
    if (node == NULL)
        return 0;

    return max(Height(node->left), Height(node->right)) + 1;
}
int Diameter(Node *root)
{
    if (root == NULL)
        return 0;

    int opt1 = Diameter(root->left);
    int opt2 = Diameter(root->right);
    int opt3 = Height(root->left) + Height(root->right);

    return max(opt3, max(opt1, opt2));
}

int main()
{
    Node *root = buildTree(1);
    cout << "Height of the tree is: " << Height(root) << endl;
    cout << "Diameter of the tree is: " << Diameter(root) << endl;

    return 0;
}