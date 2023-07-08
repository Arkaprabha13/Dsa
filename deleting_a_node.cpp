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
node *delete_head_from_head(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        node *temp = head->next;
        delete head;
        return temp;
    }
}
node * delete_from_end(node *head)
{
    if (head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    node *current=head;
    while(current->next->next!=NULL){
        current=current->next;
    }
    delete (current->next);
    current->next=NULL;
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
    head->next = new node(20);
    head->next->next = new node(30);
    printlist(head);
    // head = delete_head_from_head(head);
    head=delete_from_end(head);
    printlist(head);
    return 0;
}
