#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next, *prev;
    node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};
node *delete_head(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
    delete (head);
}
node *delete_end(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node*current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->prev->next=NULL;
    delete current;
    return head;
}
void printlist(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    printlist(head);
    head = delete_end(head);
    printlist(head);
    return 0;
}
