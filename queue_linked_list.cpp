#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
struct queue
{
    node *front, *rear;
    int size;
    queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enque(int x)
    {
        size++;
        node *temp = new node(x);
        if (front == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void deque()
    {
        size--;
        if (front = NULL)
        {
            return;
        }
        node *temp = front;
        front = front->next;
        if (front = NULL)
        {
            rear = NULL;
        }
        delete (temp);
    }
    int get_size() { return size; }
};
int main()
{
    return 0;
}