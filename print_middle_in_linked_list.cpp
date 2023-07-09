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
void print_middle(node *head)
{
    if (head == NULL)
    {
        return;
    }
    int count = 0;
    node *current;
    for (current = head; current != NULL; current = current->next)
    {
        count++;
    }
    current = head;
    for (int i = 0; i < count / 2; i++)
    {
        current = current->next;
    }
    cout << current->data;
}
void print_middle_efficient(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
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
    cout << "Middle of Linked List: ";
    print_middle(head);
    cout << endl;
    print_middle_efficient(head);
    return 0;
}
