// C++ program to find maximum and
// minimum in a Binary Tree
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// A tree node
class node
{
public:
    int data;
    node *left, *right;

    /* Constructor that allocates a new
    node with the given data and NULL
    left and right pointers. */
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Returns maximum value in a given
// Binary Tree

// Returns minimum value in a given Binary Tree
int findMin(struct node *root)
{
    // Base case
    if (root == NULL)
        return INT_MAX;

    // Return minimum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = findMin(root->left);
    int rres = findMin(root->right);
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}
int findMax(node *root)
{
    // Base case
    if (root == NULL)
        return INT_MIN;

    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

int get_max(node *root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    else
    {
        return max(root->data,max(get_max(root->left),get_max(root->right)));
    }
}
int get_min(node *root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    else
    {
        return min(root->data,min(get_min(root->left),get_min(root->right)));
    }
}

// Driver Code
int main()
{
    node *NewRoot = NULL;
    node *root = new node(2);
    root->left = new node(7);
    root->right = new node(5);
    root->left->right = new node(6);
    root->left->right->left = new node(1);
    root->left->right->right = new node(11);
    root->right->right = new node(9);
    root->right->right->left = new node(4);

    // Function call
    cout << "Maximum element is " << get_max(root) << endl;
    cout << "min element is " << get_min(root) << endl;

    return 0;
}
