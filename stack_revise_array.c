#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int top;
    int capacity;
    int *array;
} stack;
stack *create_stack(int capacity)
{
    stack *new_stack = (stack *)malloc(sizeof(stack));
    if (!new_stack)
    {
        return NULL;
    }
    new_stack->capacity = capacity;
    new_stack->top = -1;
    new_stack->array = malloc(capacity * sizeof(int));
    if (!new_stack->array)
    {
        return NULL;
    }
    return new_stack;
}
stack *reallocate(stack *s, int new_capacity)
{
    s->capacity = new_capacity;
    s->array = (int *)realloc(s->array, new_capacity * sizeof(int));
    if (!s->array)
    {
        return NULL;
    }
    return s;
}

int is_empty(stack *s)
{
    return s->top == -1;
}
int is_full(stack *s)
{
    return (s->top == s->capacity - 1);
}
int size(stack *s)
{
    return s->top + 1;
}
void push(stack *s)
{
    if (is_full(s))
    {
        printf("\n\n\nThe stack is full !!!!!\n\n\n");
        return;
    }
    else
    {
        int data;
        printf("Enter the data you want to insert -> ");
        scanf("%d", &data);
        s->array[++s->top] = data;
    }
}
int pop(stack *s)
{
    if (is_empty(s))
    {
        printf("\n\n\nThe stack is empty !!!!!\n\n\n");
        return -1;
    }
    else
    {
        return s->array[s->top--];
    }
}
int peek(stack *s)
{
    if (is_empty(s))
    {
        printf("The stack is empty !!!!!\n\n");
        return -1;
    }
    else
    {
        return s->array[s->top];
    }
}
void delete_stack(stack *s)
{
    if (s)
    {
        if (s->array)
        {
            free(s->array);
        }
        free(s);
    }
}
void display_stack(stack *s)
{
    if (is_empty(s))
    {
        printf("\n\nThe stack is empty\n\n");
        return;
    }
    else
    {
        int i;
        for (i = s->top; i >= 0; i--)
        {
            printf("| %d |\n", s->array[i]);
        }
        printf("|____|");
    }
}

int main()
{
    stack *s;
    int capacity, choice, data;
    printf("Enter the capacity of the stack -> ");
    scanf("%d", &capacity);
    s = create_stack(capacity);
    do
    {
        printf("\n\nMenu for stack operations using array !!! \n\n");
        printf("1 -> Push into the stack\n");
        printf("2 -> Pop the top element\n");
        printf("3 -> Peek element\n");
        printf("4 -> Display the stack\n");
        printf("5-> -> CHange the size of stack\n");
        printf("6 -> Exit\n");
        printf("Enter your choice -> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(s);
            display_stack(s);
            break;
        case 2:
            data = pop(s);
            printf("The deleted element from the stack is  -> %d\n", data);
            display_stack(s);
            break;
        case 3:
            data = peek(s);
            printf("The peek element of the stack is  -> %d\n", data);

            break;
        case 4:
            display_stack(s);
            break;
        case 5:
            printf("Enter the new capacity -> ");
            scanf("%d", &capacity);
            s = reallocate(s, capacity);
            break;

        case 6:
            delete_stack(s);
            printf("Exitting  !!!!!\n\n\n");
            exit(0);
            break;

        default:
            printf("Invalid choice!!!!\n");

            break;
        }

    } while (1);

    return 0;
}
