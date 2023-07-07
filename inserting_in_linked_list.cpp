#include<bits/stdc++.h>
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
node *insert_at_begin(node *head,int x)
{
    node *temp=new node(x);
    temp->next=head;
    return temp;
}
node * insert_at_end(node *head,int x)
{
    node * temp=new node(x);
    if(head==NULL)
    {
        return temp;
    }
    node *current=head;
    while(current!=NULL)
    {
        current=current->next;
    }
    current->next=temp;
    return head;
}

void r_print(node *head)
{
    if(head==NULL)
    {
        return ;
    }
    cout<<head->data<<" ";
    r_print(head->next);
}
int main()
{
    node *head=NULL;
    head=insert_at_begin(head,20);
    head=insert_at_begin(head,30);
    head=insert_at_begin(head,40);
    head=insert_at_begin(head,50);
    // insert_at_end(head,100);
    r_print(head);              // number gulo pichon theke asbe aktu bhab bujhe jbi
return 0;
}
