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
void remove_duplicates(node*head)
{
    node*current=head;
    while (current!=NULL && current->next!=NULL)
    {
        if(current->data==current->next->data)
        {
            node*temp=current->next;
            current->next=current->next->next;
            delete(temp);
        }
        else
        current=current->next;
    }
    
}
int main()
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(20);
    head->next->next->next = new node(50);
    head->next->next->next->next = new node(50);
    printlist(head);
    remove_duplicates(head);
    printlist(head);
    return 0;
}