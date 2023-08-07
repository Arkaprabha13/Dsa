#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int top;
    int capacity;
    int *array;
} stack;
stack *allocate()
{

    int capacity;
    printf("Enter the capacity of the stack -> ");
    scanf("%d", &capacity);
    stack *st = (stack *)malloc(sizeof(stack));
    if (!st)
    {
        return NULL;
    }
    st->capacity = capacity;
    st->top = -1;
    st->array = malloc(st->capacity * sizeof(int));
    if (!st->array)
    {
        return NULL;
    }
    return st;
}
int isEmpty(stack *s)
{
    return (s->top == -1);
}
int isFULL(stack *s)
{
    return (s->top == s->capacity - 1);
}
int get_size(stack *s)
{
    return s->top + 1;
}
void push(stack *s)
{
    int data;
    printf("Enter the data you want to push in the stack -> ");
    scanf("%d", &data);
    if (isFULL(s))
    {
        printf("\nStack memory is FULL !!\n"); // stack overflow condition
        return;
    }
    else
    {
        s->array[s->top++] = data;
    }
    // printf("\nThe stack after inserting  \n ");
    // display(s);
}
int pop(stack *s)
{

    if (isEmpty(s))
    {
        printf("\nStack is empty !!\n");
        return -1;
    }
    else
    {
        return s->array[--s->top];
    }
    // pSrintf("\nThe stack after deletion \n ");
    // display(s);
}
int peak(stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is empty !!\n");
        return -1;
    }
    else
    {
        return s->array[s->top];
    }
}
void delete(stack *s)
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
void display(stack *s)
{

    printf("\nThe stack is -> \n");
    if (isEmpty(s))
    {
        printf("\nstack is empty \n");
        return;
    }
    else
    {
        while (s->top >= 0)
        {
            printf(" %d ", s->array[s->top++]);
        }
    }
    printf("\n");
}
int main()
{
    int options, operations;
    stack *s;
    printf("\nEnter the number of operations you want to do -> ");
    scanf("%d", &operations);
    while (operations--)
    {

        printf("\n");
        printf("\n************The options***************\n");
        printf("\n1-> Create stack\n");
        printf("\n2-> push to stack\n");
        printf("\n3-> pop to stack\n");
        printf("\n4-> delete stack\n");
        printf("\n5-> EXIT !! \n");
        printf("Enter the operation you want to do with stack -> ");
        scanf("%d", &operations);
        switch (operations)
        {
        case 1:
            s = allocate();
            break;
        case 2:
            push(s);
            break;
        case 3:
            printf("removed element -> %d", pop(s));
            display(s);
            break;
        case 4:
            delete (s);
            break;
        case 5:
            return 0;
            break;

        default:
            printf("Enter the operation you want to do with stack -> ");
            scanf("%d", &operations);
            break;
        }
    }

    return 0;
}
