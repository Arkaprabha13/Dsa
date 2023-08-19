#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
int isBalanced(node *root)
{
    if (root == NULL)
        return 0;
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}

bool is_sum(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int sum = 0;
    if (root->left != NULL)
    {
        sum += root->left->data;
    }
    if (root->right != NULL)
    {
        sum += root->right->data;
    }
    return (root->data == sum && is_sum(root->left) && is_sum(root->right));
}
int main()
{
    node *root = new node(20);
    root->left = new node(8);
    root->right = new node(12);
    root->right->left = new node(3);
    root->right->right = new node(9);
    cout << is_sum(root);
    if (isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}