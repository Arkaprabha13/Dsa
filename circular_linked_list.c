#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
int length(node *head)
{
    int count = 1;
    node *current = head;
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        while (current != head)
        {
            count++;
        }
    }
    return count;
}
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("\n\n!! Memory allocation failed !!\n\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = new_node;
    return new_node;
}
node *insert_at_start(node *head)
{
    int data;
    printf("Enter the data for the new node -> ");
    scanf("%d", &data);
    node *new_node = create_node(data);
    if (head == NULL)
    {
        new_node->next = new_node; // Point to itself to make it circular
        return new_node;
    }

    new_node->next = head;

    // Update the last node's next pointer to point to the new first node
    node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }
    current->next = new_node;

    return new_node; // Return new_node as the new head
}

node *insert_at_end(node *head)
{
    int data;
    printf("Enter the data that you want to enter in the beginning -> ");
    scanf("%d", &data);
    node *new = create_node(data);
    if (head == NULL)
    {
        new->next = new; // Make it circular
        return new;
    }

    node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }
    current->next = new;
    new->next = head;
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
    if (position >= length(head))
    {
        printf("\n\n !! Invalid position !!\n\n");
        return head;
    }
    if (position == 0)
    {
        head = insert_at_start(head);
        return head;
    }
    int data;
    printf("Enter the data that you want to enter in %d th position -> ", position);
    scanf("%d", &data);
    node *new = create_node(data);
    node *current = head;
    int i = 0;
    while (current->next != head && i < position - 1)
    {
        current = current->next;
        i++;
    }
    new->next = current->next;
    current->next = new;

    return head;
}

node *delete_start_node(node *head)
{
    if (head == NULL)
    {
        printf("\n\n!! Empty !!\n\n");
        return head;
    }

    node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }

    // Update the last node's next pointer to point to the new first node
    current->next = head->next;

    node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

node *delete_end_node(node *head)
{
    if (head == NULL)
    {
        printf("\n\n!! Empty list !!\n\n");
        return head;
    }

    // Check if there is only one node in the list
    if (head->next == head)
    {
        free(head);
        return NULL; // Set head to NULL to indicate an empty list
    }

    node *current = head;
    node *previous = NULL;

    // Traverse the list to find the last and previous nodes
    while (current->next != head)
    {
        previous = current;
        current = current->next;
    }

    // Update the previous node's next pointer to point to the new last node
    previous->next = head;

    // Free the last node
    free(current);

    return head;
}

node *delete(node *head)
{
    if (head == NULL)
    {
        printf("\n\n !! Empty list !!\n\n");
        return head;
    }

    int position;
    printf("Enter the position at which you want to perform deletion -> ");
    scanf("%d", &position);

    int list_size = 0;
    node *current = head;
    do
    {
        list_size++;
        current = current->next;
    } while (current != head);

    if (position < 1 || position > list_size)
    {
        printf("\n\nInvalid position\n\n");
        return head;
    }

    if (position == 1)
    {
        return delete_start_node(head);
    }

    current = head;
    for (int i = 1; i < position - 1; i++)
    {
        current = current->next;
    }
    node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}
void display_linked_list(node *head)
{
    if (head == NULL)
    {
        printf("\n\n!! Empty !!\n\n");
        return;
    }
    node *current = head;
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
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
            linked_list = insert_at_start(linked_list);
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
            linked_list = delete_start_node(linked_list);
            display_linked_list(linked_list);
            break;

        case 5:
            linked_list = delete_end_node(linked_list);
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
