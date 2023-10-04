#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree;

tree *create_node(int data)
{
    tree *new_node = (tree *)malloc(sizeof(tree));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

tree *insert(tree *root, int data)
{
    if (root == NULL)
    {
        return create_node(data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the minimum value node in the BST
tree *find_minimum_value_node(tree *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

tree *delete(tree *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct TreeNode *temp = find_minimum_value_node(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

tree *search(tree *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data > data)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
}

int height_of_tree(tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = height_of_tree(root->left);
        int right_height = height_of_tree(root->right);
        if (left_height > right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }
}

void inorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct TreeNode *root = NULL;
    char choice;
    int data;

    do
    {
        printf("\nMenu:\n");
        printf("a) Insert an element\n");
        printf("b) Delete an element\n");
        printf("c) Search for an element\n");
        printf("d) Find the height of the tree\n");
        printf("e) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'a':
            printf("Enter element to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 'b':
            printf("Enter element to delete: ");
            scanf("%d", &data);
            root = delete(root, data);
            break;
        case 'c':
            printf("Enter element to search: ");
            scanf("%d", &data);
            if (search(root, data) != NULL)
            {
                printf("Element %d found in the tree.\n", data);
            }
            else
            {
                printf("Element %d not found in the tree.\n", data);
            }
            break;
        case 'd':
            printf("Height of the tree: %d\n", height_of_tree(root));
            break;
        case 'e':
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

        // Display the tree after each operation
        printf("Inorder: ");
        inorder(root);
        printf("\nPreorder: ");
        preorder(root);
        printf("\nPostorder: ");
        postorder(root);
        printf("\n");

    } while (choice != 'e');

    return 0;
}
