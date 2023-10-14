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
Node *get_floor(Node *root, int x)
{
    Node *result = NULL;
    while (root != NULL)
    {
        if (root->key == x)
        {
            return root;
        }
        else if (root->key > x)
        {
            root = root->right;
        }
        else
        {
            result = root;
            root = root->right;
        }
    }
    return result;
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
    int x = 17;

    cout << "Floor: " << (get_floor(root, 19)->key);
    // cout << endl;
    // inorder(root);
}



/*
new method of findinf floor in BST
  void inorder(Node*root,int x,int &ans)
    {
        if(root!=NULL)
        {
            inorder(root->left,x,ans);
            if(root->data<=x)
            {
                ans=min(x,root->data);
            }
            inorder(root->right,x,ans);
        }
    }
    int floor(Node* root, int x) {
        // Code here
        int ans=-1;
        inorder(root,x,ans);
        return ans;
        
    }

*/
