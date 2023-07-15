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
    while (current != NULL || !s.empty())       // or s.empty()==false
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

    inorder_iterative(root);
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