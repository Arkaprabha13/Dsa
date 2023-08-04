// #include <bits/stdc++.h>
// using namespace std;
// struct node
// {
//     int data;
//     node *next;
//     node(int x)
//     {
//         data = x;
//         next = NULL;
//     }
// };
// void printlist(node *head)
// {
//     node *curr = head;
//     while (curr != NULL)
//     {
//         cout << curr->data << " ";
//         curr = curr->next;
//     }
//     cout << endl;
// }

// node *reverseK(node *head, int k)
// {
//     node *current = head;
//     node *prev = NULL;
//     node *next = NULL;
//     int count = 0;
//     while (current->next != NULL && count < k)
//     {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//         count++;
//     }
//     if (next != NULL)
//     {
//         node *rest_head = reverseK(next, k);
//         head->next = rest_head;
//     }
//     return prev;
// }

// int main()
// {
//     node *head = new node(10);
//     head->next = new node(20);
//     head->next->next = new node(30);
//     head->next->next->next = new node(40);
//     head->next->next->next->next = new node(50);
//     head->next->next->next->next->next = new node(60);
//     head->next->next->next->next->next->next = new node(70);
//     printlist(head);
//     head = reverseK(head, 3);
//     printlist(head);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *reverseK(Node *head, int k)
{
    Node *curr = head, *next = NULL, *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        Node *rest_head = reverseK(next, k);
        head->next = rest_head;
    }
    return prev;
}
// iteravtive 
Node *i_reverseK(Node *head,int k){
    Node *curr=head,*prevFirst=NULL;
    bool isFirstPass=true;
    while(curr!=NULL){
        Node *first=curr,*prev=NULL;
        int count=0;
        while(curr!=NULL&&count<k){
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
        }
        if(isFirstPass){head=prev;isFirstPass=false;}
        else{prevFirst->next=prev;}
        prevFirst=first;
    }
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = new Node(70);
    printlist(head);
    head = i_reverseK(head, 3);
    printlist(head);
    return 0;
}
