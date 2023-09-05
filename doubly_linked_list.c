#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed!!!\n\n\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
node *insert_start(node *head)
{
    int data;
    printf("Enter the data that you want to enter in the beginning -> ");
    scanf("%d", &data);
    node *new = create_node(data);
    if (head == NULL)
    {
        return new;
    }

    head->prev = new;
    new->next = head;
    new->prev = NULL; // Set the previous of the new node to NULL as it's the new head
    return new;       // Return the new node as the new head
}
node *insert_at_end(node *head)
{
    int data;
    printf("Enter the data that you want to enter in the beginning -> ");
    scanf("%d", &data);
    node *new = create_node(data);
    if (head == NULL)
    {
        return new;
    }

    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    new->prev = current;
    current->next = new;
    new->next = NULL;
    return head;
}
node *insert(node *head)
{
    int position;
    printf("Enter the position where you want to enter the data -> ");
    scanf("%d", &position);
    if (position < 0)
    {
        printf("\n\nInvalid position\n\n");
        return head;
    }
    if (position == 0)
    {
        head = insert_start(head);
        return head;
    }
    int data;
    printf("Enter the data that you want to enter in %d th position -> ", position);
    scanf("%d", &data);
    node *new = create_node(data);
    node *current = head;
    int i = 0;
    while (current->next != NULL && i < position - 1)
    {
        current = current->next;
        i++;
    }
    new->prev = current;
    new->next = current->next;
    current->next = new;
    return head;
}
node *delete_start(node *head)
{
    if (head == NULL)
    {
        printf("\n\n!! Empty !! \n\n");
        return head;
    }
    if (head->next == NULL)
    {
        node *temp = head;
        head = temp->next;
        free(temp);
        return NULL;
    }
    node *temp = head;
    head = temp->next;
    free(temp);
    return head;
}
/*                                   by chatgpt
node *delete_start(node *head)
{
    if (head == NULL)
    {
        printf("\n\n!! Empty !! \n\n");
        return head;
    }

    node *temp = head;

    if (head->next != NULL)
    {
        head = temp->next;
        head->prev = NULL;
    }
    else
    {
        head = NULL; // List becomes empty
    }

    free(temp);
    return head;
}

*/
node *delete_end(node *head)
{
    if (head == NULL)
    {
        printf("\n\n !! Empty !! \n\n");
        return head;
    }
    if (head->next == NULL)
    {
        // If there is only one node in the list, delete it and set head to NULL
        free(head);
        return NULL;
    }
    node *currrent = head;
    while (currrent->next->next != NULL)
    {
        currrent = currrent->next;
    }
    node *temp = currrent->next;
    currrent->next = NULL;
    free(temp);
    return head;
}
node *delete(node *head)
{
    int position;
    printf("Enter the position where you want to enter the data -> ");
    scanf("%d", &position);
    if (position < 0)
    {
        printf("\n\nInvalid position\n\n");
        return head;
    }
    if (position == 0)
    {
        head = delete_start(head);
        return head;
    }
    node *current = head;
    int i = 0;
    while (current->next != NULL && i < position - 1)
    {
        current = current->next;
        i++;
    }
    current->next->prev = current;
    node *temp = current->next;
    current->next = temp->next;

    free(temp);
    return head;
}

void display_linked_list(node *head)
{
    if (head == NULL)
    {
        printf("\n! Empty ! \n");
        return;
    }
    node *current = head;
    printf(" \n The linked list is \n ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice;
    node *linked_list = NULL;
    do
    {
        printf("Menu for Doubly Linked List operations\n");
        printf("1 -> Insert at beginning\n");
        printf("2 -> Insert at end\n");
        printf("3 -> Insert at position\n");
        printf("4 -> Delete at start\n");
        printf("5 -> Delete the end \n");
        printf("6 -> Delete at a position\n");
        printf("7 -> Exit\n");
        printf("Enter your choice -> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            linked_list = insert_start(linked_list);
            display_linked_list(linked_list);
            break;

        case 2:
            linked_list = insert_at_end(linked_list);
            display_linked_list(linked_list);
            break;

        case 3:
            linked_list = insert(linked_list);
            display_linked_list(linked_list);
            break;

        case 4:
            linked_list = delete_start(linked_list);
            display_linked_list(linked_list);
            break;

        case 5:
            linked_list = delete_end(linked_list);
            display_linked_list(linked_list);
            break;

        case 6:
            linked_list = delete (linked_list);
            display_linked_list(linked_list);
            break;

        case 7:
            printf("\n\n !! Exiting !! \n\n");
            exit(0);
            break;

        default:
            printf("\n\nInvalid choice !!!\n\n");
            break;
        }
    } while (1);

    return 0;
}
