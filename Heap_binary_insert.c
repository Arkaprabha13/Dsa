#include <stdio.h>
#include <stdlib.h>

struct MinHeap{
    int *arr;
    int size;
    int capacity;
};
    
    
void createMinHeap(struct MinHeap* mheap, int c){
    mheap->size = 0; 
    mheap->capacity = c; 
    mheap->arr = (int*) malloc(c*sizeof(int));
}

int left(int i) { return (2*i + 1); } 
int right(int i) { return (2*i + 2); } 
int parent(int i) { return (i-1)/2; } 
void swap(int *x,int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void insert(struct MinHeap* mheap, int x) 
{ 
    if (mheap->size == mheap->capacity)return;
    mheap->size++; 
    mheap->arr[mheap->size-1]=x; 
    
    for (int i=mheap->size-1;i!=0 && mheap->arr[parent(i)]>mheap->arr[i];) 
    { 
       swap(&mheap->arr[i], &mheap->arr[parent(i)]); 
       i = parent(i); 
    } 
}
    

int main() 
{ 
    struct MinHeap h;
    createMinHeap(&h,11);
    insert(&h,3); 
    insert(&h,2);
    insert(&h,15);
    insert(&h,20);
    return 0;
} 
