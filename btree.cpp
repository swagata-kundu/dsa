#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
}

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *currentNode = q.front();
        q.pop();
        cout << currentNode->data << endl;
        if (currentNode->left)
        {
            q.push(currentNode->left);
        }
        if (currentNode->right)
        {
            q.push(currentNode->right);
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // inorder(root);
    levelOrder(root);
}