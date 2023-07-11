
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
node *reverse_a_doubly_linked_list(node*head)
{
    // if(head==NULL||head->next==NULL)
    // {
    //     return head;
    // }

        // swapping
        node *temp=NULL;
    node *curr=head;
    while(curr!=NULL){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    if(temp!=NULL)head=temp->prev;
    return head;    
    


    // return prev->prev;
    
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
    reverse_a_doubly_linked_list(head);
    printlist(head);
    return 0;
}
