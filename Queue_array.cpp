#include <bits/stdc++.h>
using namespace std;
struct Queue_array
{
    int size, capacity;
    int *arr;
    Queue_array(int c)
    {
        capacity = c;
        size = 0;
        arr = new int[capacity];
    }
    bool isFULL()
    {
        return (size == capacity);
    }
    bool is_empty()
    {
        return (size == 0);
    }
    void enque(int x) // adding
    {
        if (isFULL())
        {
            return;
        }
        arr[size]=x;
        size++;
    }
    void deque()
    {
        if(is_empty())
        {
            return;
        }
        for(int i=0;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        size--;
    }
    int get_front()
    {
        if(is_empty())
        {
            return -1;
        }
        else{
            return 0;
        }
    }
    int get_rear()
    {
        if(is_empty())
        {
            return -1;
        }
        else{
            return size-1;
        }
    }
};

int main()
{
    return 0;
}