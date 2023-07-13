#include <bits/stdc++.h>
using namespace std;
struct deque
{
    int size, capacity;
    int *arr;
    deque(int c)
    {
        capacity = c;
        size = 0;
        arr = new int[capacity];
    }
    bool is_empty()
    {
        return (size == 0);
    }
    bool is_full()
    {
        return (size == capacity);
    }
    void insert_rear(int x)
    {
        if (is_full())
        {
            return;
        }
        arr[size] = x;
        size++;
    }
    void insert_front(int x)
    {
        if (is_full())
        {
            return;
        }
        for (int i = size - 1; i >= 0; i++)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = x;
        size++;
    }
    void delete_rear()
    {
        if (is_empty())
        {
            return;
        }
        size--;
    }
    void delete_front()
    {
        if (is_empty())
        {
            return;
        }
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    int get_rear()
    {
        if (is_empty())
        {
            return -1;
        }
        else
        {
            return (size - 1);
        }
    }
    int get_front()
    {
        if (is_empty())
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
};

//  EFFICIENT solution using front

struct Deque
{
    int *arr;
    int size, front, capacity;
    Deque(int c)
    {
        capacity = c;
        size = front = 0;
        arr = new int[capacity];
    }
    bool is_empty()
    {
        return (size == 0);
    }
    bool is_full()
    {
        return (size == capacity);
    }
    void delete_front()
    {
        if (is_empty())
        {
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }
    void insert_front(int x)
    {
        if (is_full())
        {
            return;
        }
        front = (front + capacity - 1) % capacity;
        arr[front] = x;
        size++;
    }
    void delete_rear()
    {
        if (is_empty())
        {
            return;
        }
        size--;
    }
    void insert_rare(int x)
    {
        if (is_full())
        {
            return;
        }
        int new_rear = (front + size) % capacity;
        arr[new_rear] = x;
        size++;
    }
    int get_front()
    {
        if (is_empty())
        {
            return -1;
        }
        else
            return front;
    }
    int get_rear()
    {
        if (is_empty())
        {
            return -1;
        }
        else
        {
            return (front + size - 1) % capacity;
        }
    }
};
int main()
{
    return 0;
}