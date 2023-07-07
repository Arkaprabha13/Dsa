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
int search(node *head, int n)
{
    int pos=1;
    node *current=head;
    while(current!=NULL)
    {
        if(current->data==n)
        {
            return pos;
        }
        else
        {
            pos++;
            current=current->next;
        }
    }
    return -1;
}

int main()
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    cout<<recursive_search(head,30);
    return 0;
}
