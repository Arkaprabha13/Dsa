#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int *array;
    int capacity;
    int count;
    int heap_type;
} heap;

heap *create_heap(int capacity, int heap_type)
{
    heap *h = (heap *)malloc(sizeof(heap));
    if (h == NULL)
    {
        printf("Memory Error\n");
        return h;
    }
    h->heap_type = heap_type;
    h->capacity = capacity;
    h->count = 0;
    h->array = (int *)malloc(capacity * sizeof(int));
    if (h->array == NULL)
    {
        printf("Memory Error\n");
        free(h);
        return NULL;
    }
    return h;
}

void destroy_heap(heap *h)
{
    free(h->array);
    free(h);
}

int parent(heap *h, int i)
{
    if (i <= 0 || i >= h->count)
    {
        return -1;
    }
    return (i - 1) / 2;
}

int left_child(heap *h, int i)
{
    int left = 2 * i + 1;
    if (left >= h->count)
    {
        return -1;
    }
    return left;
}

int right_child(heap *h, int i)
{
    int right = 2 * i + 2;
    if (right >= h->count)
    {
        return -1;
    }
    return right;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(heap *h, int i)
{
    while (i > 0 && h->array[i] > h->array[parent(h, i)])
    {
        swap(&h->array[i], &h->array[parent(h, i)]);
        i = parent(h, i);
    }
}

void insert(heap *h, int value)
{
    if (h->count == h->capacity)
    {
        printf("Heap is full\n");
        return;
    }

    h->array[h->count] = value;
    h->count++;

    heapify_up(h, h->count - 1);
}

void heapify_down(heap *h, int i)
{
    int maxIndex = i;
    int left = left_child(h, i);
    int right = right_child(h, i);

    if (left != -1 && h->array[left] > h->array[maxIndex])
    {
        maxIndex = left;
    }

    if (right != -1 && h->array[right] > h->array[maxIndex])
    {
        maxIndex = right;
    }

    if (i != maxIndex)
    {
        swap(&h->array[i], &h->array[maxIndex]);
        heapify_down(h, maxIndex);
    }
}

int extract_max(heap *h)
{
    if (h->count == 0)
    {
        printf("Heap is empty\n");
        return -1;
    }

    int root = h->array[0];
    h->array[0] = h->array[h->count - 1];
    h->count--;

    heapify_down(h, 0);

    return root;
}

void display_heap(heap *h, int i, int level)
{
    if (i < h->count)
    {
        // Print right child
        display_heap(h, right_child(h, i), level + 1);

        // Print current node
        for (int j = 0; j < level; j++)
        {
            printf("\t\t");
        }
        printf("%d\n", h->array[i]);

        // Print left child
        display_heap(h, left_child(h, i), level + 1);
    }
}

void display(heap *h)
{
    printf("Heap structure:\n");
    // display_heap(h, 0, 0);

    printf("Heap elements: ");
    for (int i = 0; i < h->count; i++)
    {
        printf("%d ", h->array[i]);
    }
    printf("\n");
}


int main()
{
    int capacity, choice, value;
    printf("Enter the capacity of the heap: ");
    scanf("%d", &capacity);

    heap *h = create_heap(capacity, 1); // 1 for max-heap, 0 for min-heap

    do
    {
        printf("\n----- Menu -----\n");
        printf("1. Insert\n");
        printf("2. Extract Max\n");
        printf("3. Display\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(h, value);
            break;

        case 2:
            printf("Extracted Max: %d\n", extract_max(h));
            break;

        case 3:
            display(h);
            // printf("\n\n");
            // display_heap(h);
            break;

        case 4:
            printf("Quitting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);

    destroy_heap(h);
    return 0;
}
