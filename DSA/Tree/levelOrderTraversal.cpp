#include <iostream>
#include <queue>
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
        this->left = this->right = NULL;
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

void Traverse(Node *root)
{

    if (root != nullptr)
    {
        cout << root->data << " ";
        Traverse(root->left);
        Traverse(root->right);
    }
}

void levelTraverse(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {

            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *tree;
    tree = buildTree(1);
    Traverse(tree);

    cout << endl;
    levelTraverse(tree);

    return 0;
}