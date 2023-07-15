#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int x)
    {
        this->data = x;
        left = right = NULL;
    }
};
void inorder_iterative(node *root)
{
    stack<node *> s;
    node *current = root;
    while (current != NULL || !s.empty()) // or s.empty()==false
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
}
void preorder_iterative(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> s;
    s.push(root);
    while (!s.empty())
    {
        node *current = s.top();
        cout << current->data << " ";
        s.pop();
        if (current->right)
        {
            s.push(current->right);
        }
        if (current->left)
        {
            s.push(current->left);
        }
    }
}
void preorder_iterative_space_efficiency(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> s;
    s.push(root);
    node *current = root;
    while (!s.empty())
    {
        while (current != NULL)
        {
            cout << current->data << " ";
            if (current->right != NULL)
            {
                s.push(current->right);
            }
            current = current->left;
        }
        if (!s.empty())
        {
            current = s.top();
            s.pop();
        }
    }
}
void iterativePreorder(node *root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty stack and push root to it
    stack<node *> nodeStack;
    nodeStack.push(root);

    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false)
    {
        // Pop the top item from stack and print it
        struct node *node = nodeStack.top();
        printf("%d ", node->data);
        nodeStack.pop();

        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}

int main()
{

    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    cout << " in order traversal -> ";
    inorder_iterative(root);
    cout << " pree order traversal -> ";
    // iterativePreorder(root);
    preorder_iterative(root);
    cout<<"\nSpace efficient solution - > ";
    preorder_iterative_space_efficiency(root);
    return 0;
}
// C++ program to print inorder traversal
// using stack.
// #include<bits/stdc++.h>
// using namespace std;

// /* A binary tree Node has data, pointer to left child
//    and a pointer to right child */
// struct Node
// {
//     int data;
//     struct Node* left;
//     struct Node* right;
//     Node (int data)
//     {
//         this->data = data;
//         left = right = NULL;
//     }
// };

/* Iterative function for inorder tree
   traversal */
// void inOrder(struct Node *root)
// {
//     stack<Node *> s;
//     Node *curr = root;

//     while (curr != NULL || s.empty() == false)
//     {
//         /* Reach the left most Node of the
//            curr Node */
//         while (curr !=  NULL)
//         {
//             /* place pointer to a tree node on
//                the stack before traversing
//               the node's left subtree */
//             s.push(curr);
//             curr = curr->left;
//         }

//         /* Current must be NULL at this point */
//         curr = s.top();
//         s.pop();

//         cout << curr->data << " ";

//         /* we have visited the node and its
//            left subtree.  Now, it's right
//            subtree's turn */
//         curr = curr->right;

//     } /* end of while */
// }

// /* Driver program to test above functions*/
// int main()
// {

//     /* Constructed binary tree is
//               1
//             /   \
//           2      3
//         /  \
//       4     5
//     */
//     struct Node *root = new Node(1);
//     root->left        = new Node(2);
//     root->right       = new Node(3);
//     root->left->left  = new Node(4);
//     root->left->right = new Node(5);

//     inOrder(root);
//     return 0;
// }
