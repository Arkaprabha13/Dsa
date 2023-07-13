#include <bits/stdc++.h>
using namespace std;
struct Queue_array
{
    int front, size, capacity;
    int *arr;
    Queue_array(int c)
    {
        capacity = c;
        size = front = 0;
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
    int get_front()
    {
        if (is_empty())
        {
            return -1;
        }
        else
        {
            return front;
        }
    }
    int get_rear()
    {
        if (is_empty())
        {
            return -1;
        }
        else
        {
            return (front + size - 1)%capacity;
        }
    }
    void enque(int x) // adding
    {
        if (isFULL())
        {
            return;
        }
       int rear=get_rear();
       rear=(rear+1)%capacity;
       arr[rear]=x;
    }
    void deque()
    {
        if(is_empty())
        {
            return;
        }
        front=(front+1)%capacity;
        size--;
    }
};
int main()
{
    return 0;
}