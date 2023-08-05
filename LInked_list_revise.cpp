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
void display(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}
node *insert_at_begin(node *head)
{
    int x;
    cout << "Enter the value which you want to add in the beginging -> ";
    cin >> x;
    node *new_node = new node(x);
    if (head == NULL)
    {
        new_node->next = NULL;
        head = new_node;
        return head;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
    return head;
}
node *insert_at_end(node *head)
{
    int x;
    cout << "Enter the value which you want to add in the beginging -> ";
    cin >> x;
    node *new_node = new node(x);
    if (head == NULL)
    {
        new_node->next = NULL;
        head = new_node;
        return head;
    }
    else
    {
        node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = NULL;
    }
    return head;
}
node *insert_at_a_postion(node *head)
{
    int x;
    cout << "Enter the value which you want to add in the beginging -> ";
    cin >> x;
    node *new_node = new node(x);
    int position;
    cout << "Enter the position at which you want to add the new element - >";
    cin >> position;
    if (head == NULL)
    {
        new_node->next = NULL;
        head = new_node;
        return head;
    }
    else
    {
        node *current = head;
        while (current->next != NULL && position--)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return head;
}
void delete_first_node(node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }
    else
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
}
void delete_at_a_position(node *head)
{

    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    int position;
    cout << "Enter the position of the node to delete -> ";
    cin >> position;

    if (position <= 0)
    {
        cout << "Invalid position!\n";
        return;
    }

    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    node *current = head;
    int count = 1;
    while (current != NULL && count < position - 1)
    {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL)
    {
        cout << "Position out of range!\n";
        return;
    }

    node *temp = current->next;
    current->next = temp->next;
    free(temp);
}
/* Checks whether the value x is present in linked list */
bool search(struct node *head, int x)
{
    // Base case
    if (head == NULL)
        return false;

    // If key is present in current node, return true
    if (head->data == x)
        return true;

    // Recur for remaining list
    return search(head->next, x);
    /*          iterative
     Node* current = head; // Initialize current
    while (current != NULL)
    {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false; */
}
int getsize(node *head)
{
    int counter = 0;
    node *current = head;
    while (current->next != NULL)
    {
        counter++;
        current = current->next;
    }
    return counter;
}
void print_middle(node *head)
{
    // two pointer approach
    node *slow = head;
    node *fast = head;
    if (head != NULL)
    {
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "The middle eleemtn is -> " << slow->data;
    }
}
void reverse(node *&head)
{
    // Initialize current, previous and
    // next pointers
    node *current = head;
    node *prev = NULL;
    node *next = NULL;
    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    display(head);
}
// recursive approach
node *reverse(node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->next == NULL)
    {
        head = node;
        return node;
    }
    node *temp = reverse(node->next);
    temp->next = node;
    node->next = NULL;
    return node
}
// two pointer approach
struct node *reverseList(struct node *head)
{
    struct node *current = head;
    struct node *next;
    while (current->next != NULL)
    {
        next = current->next;
        current->next = next->next;
        next->next = head;
        head = next;
    }
    return head;
}
int main()
{
    node *head = NULL;
    // display(head);
    cout << endl
         << endl
         << endl;
    int n1;
    cout << "Enter the number of values that you want to insert at begin -> ";
    cin >> n1;
    while (n1--)
    {
        head = insert_at_begin(head);
    }
    display(head);
    cout << endl
         << endl
         << endl;
    int n2;
    cout << "Enter the number of values that you want to insert at end -> ";
    cin >> n2;
    while (n2--)
    {
        head = insert_at_end(head);
    }
    display(head);
    cout << endl
         << endl
         << endl;
    int n3;
    cout << "Enter the number of values that you want to insert a -> ";
    cin >> n3;
    while (n3--)
    {
        head = insert_at_a_postion(head);
    }
    display(head);
    cout << endl;
    cout << "Deleting the node at start !! \n";
    delete_first_node(head);
    display(head);
    int n4;
    cout << "\nHow many elements you want to delete from the list ? -> ";
    cin >> n4;
    while (n4--)
    {
        delete_at_a_position(head);
        cout << "AFter the deletion \n";
        display(head);
    }
    cout << endl;
    print_middle(head);
    cout << endl;
    reverse(head);

    return 0;
}