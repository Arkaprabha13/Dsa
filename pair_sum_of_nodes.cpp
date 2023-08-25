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

void treeToList(Node *root, vector<int> &list)
{
    if (root == NULL)
        return;

    treeToList(root->left, list);
    list.push_back(root->key);
    treeToList(root->right, list);
}

bool isPairPresent_inorder(Node *root, int target)
{
    vector<int> a2;

    treeToList(root, a2);

    int start = 0;

    int end = a2.size() - 1;

    while (start < end)
    {

        if (a2[start] + a2[end] == target)
        {
            cout << "Pair Found: " << a2[start] << " + " << a2[end] << " "
                 << "= " << target;
            return true;
        }

        if (a2[start] + a2[end] > target) // decrements end
        {
            end--;
        }

        if (a2[start] + a2[end] < target) // increments start
        {
            start++;
        }
    }

    cout << "No such values are found!";
    return false;
}

bool isPairSum_hashing(Node *root, int sum, unordered_set<int> &s)
{
    if (root == NULL)
        return false;

    if (isPairSum_hashing(root->left, sum, s) == true)
        return true;

    if (s.find(sum - root->key) != s.end())
        return true;
    else
        s.insert(root->key);
    return isPairSum_hashing(root->right, sum, s);
}
int main()
{

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(20);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);
    root->right->right->left = new Node(25);

    int sum = 33;

    isPairPresent_inorder(root, sum);

	Node *root1 = new Node(10);  
    root1->left = new Node(8);  
    root1->right = new Node(20);  
    root1->left->left = new Node(4);
    root1->left->right = new Node(9);
    root1->right->left = new Node(11);
    root1->right->right = new Node(30);  
    root1->right->right->left = new Node(25);
        
    // int sum=33;
    unordered_set<int> s;    
    cout<<endl<<isPairSum_hashing(root1,sum,s);
    return 0;
}