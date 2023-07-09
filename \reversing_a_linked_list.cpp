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
node *reverse(node *head)
{
    vector<int> a;
    for (node *c = head; c != NULL; c = c->next)
    {
        a.push_back(c->data);
    }
    for (node *c = head; c != NULL; c = c->next)
    {
        c->data = a.back();
        a.pop_back();
    }
    return head;
}
node *reverse_nodes(node *head)
{
    node *current = head;
    node *previous = NULL;
    while (current != NULL)
    {
        node *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}
node *recursive_method_1_reverse_a_linked_list(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *rest_head = recursive_method_1_reverse_a_linked_list(head->next);
    node *rest_tail = head->next;
    head->next = NULL;
    return rest_head;
}
node *recursive_method_2_reverse_a_linked_list(node *current, node *previous)
{
    if(current==NULL)
    {
        return previous;
    }
    node *next = current->next;
    current->next = previous;
    return recursive_method_2_reverse_a_linked_list(next, current);
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
    // reverse(head);
    recursive_method_2_reverse_a_linked_list(head,NULL);
    printlist(head);
    return 0;
}
