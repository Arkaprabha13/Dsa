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
        printf("Memory Error");
        return h;
    }
    h->heap_type = heap_type;
    h->capacity = capacity;
    h->count = 0;
    h->array = (int *)malloc(sizeof(int));
    if (h->array == NULL)
    {
        printf("Memory Error");
        return h;
    }
    return h;
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
int get_maximum(heap *h)
{
    if (h->count == 0)
    {
        return -1;
    }
    return h->array[0];
}

// heapyfiyng the element at location i
void percolate_down(heap *h, int i)
{
    int left, right, max, temp;
    left = left_child(h, i);
    right = right_child(h, i);
    if (left != -1 && h->array[left] > h->array[i])
    {
        max = left;
    }
    else
    {
        max = i;
    }
    if (right != -1 && h->array[right] > h->array[max])
    {
        max = right;
    }
    if (max != i)
    {
        // swapping
        temp = h->array[i];
        h->array[i] = h->array[max];
        h->array[max] = temp;
        percolate_down(h, max);
    }
}
void percolate_up(heap *h, int i)
{
}
int delete_maximum(heap *h)
{
    int data;
    if (h->count == 0)
    {
        return -1;
    }
    data = h->array[0];
    h->array[0] = h->array[h->count - 1];
    h->count--; // reducing heap size;
    percolate_down(h, 0);
    return data;
}
void heap_resize(heap *h)
{
    int *old_array = h->array;
    h->array = (int *)malloc(sizeof(int) * h->capacity * 2);
    if (h->array == NULL)
    {
        printf("memory error");
        return;
    }
    for (int i = 0; i < h->capacity; i++)
    {
        h->array[i] = old_array[i];
    }
    h->capacity *= 2;
    free(old_array);    
}
int insert(heap *h, int data)
{
    int i;
    if (h->count == h->capacity)
    {
        heap_resize(h);
    }
    h->count++;
    i = h->count - 1;
    while (i >= 0 && data > h->array[(i - 1) / 2])
    {
        h->array[i] = h->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->array[i] = data;
}
int main()
{

    return 0;
}
