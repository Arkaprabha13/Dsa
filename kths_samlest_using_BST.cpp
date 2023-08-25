#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int lCount;
    Node(int k)
    {
        key = k;
        left = right = NULL;
        lCount = 0;
    }
};

struct Node1
{
    int key;
    struct Node1 *left;
    struct Node1 *right;
    Node1(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void printKth(Node1 *root, int k, int &count)
{
    if (root != NULL)
    {
        printKth(root->left, k, count);
        count++;
        if (count == k)
        {
            cout << root->key;
            return;
        }
        printKth(root->right, k, count);
    }
}
Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);

    if (x < root->key)
    {
        root->left = insert(root->left, x);
        root->lCount++;
    }

    else if (x > root->key)
        root->right = insert(root->right, x);
    return root;
}

Node *kthSmallest(Node *root, int k)
{
    if (root == NULL)
        return NULL;

    int count = root->lCount + 1;
    if (count == k)
        return root;

    if (count > k)
        return kthSmallest(root->left, k);

    return kthSmallest(root->right, k - count);
}

int main()
{

    Node *root2 = NULL;
    int keys[] = {20, 8, 22, 4, 12, 10, 14};

    for (int x : keys)
        root2 = insert(root2, x);
    int k = 3;
    int count = 0;
    Node1 *root = new Node1(15);
    root->left = new Node1(5);
    root->left->left = new Node1(3);
    root->right = new Node1(20);
    root->right->left = new Node1(18);
    root->right->left->left = new Node1(16);
    root->right->right = new Node1(80);
    cout << "Kth Smallest: ";
    printKth(root, k, count);
    // int k = 4;
    cout<<endl;
    Node *res = kthSmallest(root2, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Smallest Element is " << res->key;
    return 0;
}