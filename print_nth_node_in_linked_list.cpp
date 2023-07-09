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
void print_nth_node_from_end(node *head, int n)
{
    int len = 0;
    for (node *current = head; current != NULL; current = current->next)
    {
        len++;
    }
    if (len < n)
    {
        return;
    }
    node *current = head;
    for (int i = 1; i < len - n + 1; i++)
    {
        current = current->next;
    }
    cout << current->data;
}
//      Two pointer approach
void print_nth_end(node *head, int n)
{
    if (head == NULL)
    {
        return;
    }
    node *first = head, *second = head;

    for (int i = 1; i < n; i++)
    {
        if (first == NULL)
        {
            return;
        }
        first = first->next;
    }

    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }
    cout << second->data;
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
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);
    printlist(head);
    // cout << "Middle of Linked List: ";
    print_nth_node_from_end(head, 2);
    cout << endl;
    // print_middle_efficient(head);
    return 0;
}