#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data = x; //   galti se bhi x=data nhi karna
        next = prev = NULL;
    }
};
node *insert_at_begin(node *head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    if (head == NULL)
    {
        head->prev = temp;
        // temp->prev = NULL;
    }
    return temp;
}
node * insert_at_end(node*head,int data)
{
   node *temp = new node(data);
    if (head == NULL)
    {
        return temp;
    }
    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next=temp;
    temp->prev=current;
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

    head = insert_at_begin(head, 5);
    printlist(head);
    return 0;
}
