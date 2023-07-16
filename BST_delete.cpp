#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
Node *get_succesor(Node *root)
{
    root = root->right;
    while (root->right != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *recursive_delete(Node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->key > x)
    {
        root->left = recursive_delete(root->left, x);
    }
    else if (root->key < x)
    {
        root->right = recursive_delete(root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = get_succesor(root);
            root->key = temp->key;
            root->right = recursive_delete(root->right, temp->key);
        }
    }
}
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
int main()
{

    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->right = new Node(80);
    // int x = 16;
    inorder(root);
    recursive_delete(root, 15);
    cout << endl;
    inorder(root);
}