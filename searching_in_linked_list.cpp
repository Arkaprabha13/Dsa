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
int recursive_search(node *head,int x)
{
    if(head==NULL)
    {
        return -1;
    }
    if(head->data==x)
    {
        return 1;
    }
    else{
        int result=recursive_search(head->next,x);
        if(result==-1)
        {
            return -1;
        }
        else return (result+1);
    }
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
