#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
node *create(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node)
    {
        printf("Memory allocation failed \n\n");
    }
    new_node->data = data;
    new_node->prev = new_node->next = NULL;
}
void insert_at_beggining(node **head, int data)
{
    node *new = create(data);
    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        new->prev = NULL;
        new->next = (*head);
        (*head)->prev = new;
        (*head) = new;
    }
}
void display(node *head)
{
    if (head == NULL)
    {
        printf("List Empty\n");
        return;
    }
    node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n"); // Added to indicate the end of the list
    return;
}
void insert_at_end(node **head, int data)
{
    node *new = create(data);
    if (*head == NULL)
    {
        *head = new;
    }
    node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new;
    new->prev = current->next;
    new->next = NULL;
}
void insert_at_position(node **head, int data, int position)
{
    if (position <= 0)
    {
        printf("Invalud place !\n");
        return;
    }
    if (position == 1)
    {
        insert_at_beggining(head, data);
        return;
    }
    node *new = create(data);
    node *current = *head;
    int i = 0;
    while (i < position - 1 && current->next != NULL)
    {
        i++;
        current = current->next;
    }
    if (current->next != NULL)
    {
        new->next = current->next;
        current->next->prev = new;
    }
    current->next = new;
    new->prev = current;
}
void delete_start(node **head)
{
    if (*head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    else
    {
        node *temp = *head;
        *head = (*head)->next;

        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }

        free(temp);
    }
}
void delete_end(node **head)
{
    if (*head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    node *current = *head;

    // Traverse to the last node
    while (current->next != NULL)
    {
        current = current->next;
    }

    if (current->prev != NULL)
    {
        current->prev->next = NULL;
    }
    else
    {
        // If there's only one node in the list
        *head = NULL;
    }

    free(current);
}
void delete_at_position(node **head, int position)
{
    if (*head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    if (position <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 1)
    {
        delete_start(head);
        return;
    }

    int i = 1;
    node *current = *head;

    // Traverse to the node at the specified position
    while (i < position && current != NULL)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)
    {
        printf("Position not found\n");
        return;
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }

    free(current);
}

int main()
{
    node *head = NULL;
    insert_at_beggining(&head, 10);
    insert_at_beggining(&head, 20);
    insert_at_beggining(&head, 30);
    insert_at_beggining(&head, 40);
    insert_at_beggining(&head, 50);
    insert_at_beggining(&head, 60);

    insert_at_end(&head, 70);
    insert_at_end(&head, 80);
    insert_at_end(&head, 90);
    insert_at_end(&head, 100);

    insert_at_position(&head, 100, 3);
    insert_at_position(&head, 990, 3);
    insert_at_position(&head, 880, 3);
    insert_at_position(&head, 708, 3);

    display(head);
    return 0;
}
// 60 -> 50 -> 40 -> 708 -> 880 -> 990 -> 100 -> 30 -> 20 -> 10 -> 70 -> 80 -> 90 -> 100 -> NULL