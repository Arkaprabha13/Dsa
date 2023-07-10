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
node *insert_at_begining(node *head, int x)
{
    node *temp = new node(x);
    if (head == NULL)
    {
        temp->next = temp;
    }
    else
    {
        node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = temp;
        temp->next = head;
    }
    return temp;
}
node *insert_at_end(node *head, int x)
{
    node *temp = new node(x);
    if (head == NULL)
    {
        temp->next = temp;
    }
    else
    {
        node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = temp;
        temp->next = head;
    }
    return temp;
}

void print_list(node *head)
{
    if (head == NULL)
    {
        return;
    }
    // cout<<head->data;cout<<endl;
    // for(node*p=head->next;p!=head;p=p->next)
    // {
    //     cout<<p->data<<" ";
    // }
    //                      or
    node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
}
int main()
{
    node *head = new node(13);
    head->next = new node(30);
    print_list(head);
    optimised_insertion_at_head(head, 40);
    print_list(head);

    return 0;
}
