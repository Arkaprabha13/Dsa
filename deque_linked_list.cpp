// #include <bits/stdc++.h>
// using namespace std;
// struct node
// {
//     int data;
//     node *next, *prev;
//     node(int c)
//     {
//         data = c;
//         next = prev = NULL;
//     }
// };
// class deque
// {
// private:
//     node *front, *rear;
//     int size;

// public:
//     deque() : front(nullptr), rear(nullptr), size(0) {}
//     bool is_empty()
//     {
//         return (size == 0);
//     }
//     void insert_front(int data)
//     {

//         node *temp = new node(data);
//         temp->prev = NULL;
//         temp->next = front;
//         if (front != NULL)
//         {
//             front->prev = temp;
//         }
//         else
//         {
//             rear = temp;
//         }
//         front = temp;
//         size++;
//     }
//     void insert_end(int data)
//     {
//         node *temp = new node(data);
//         temp->prev = rear;
//         temp->next = NULL;
//         if (rear != NULL)
//         {
//             rear->next = temp;
//         }
//         else
//         {
//             front = temp;
//         }
//         rear = temp;
//         size++;
//     }
//     void delete_front()
//     {
//         if (front == nullptr and rear == nullptr)
//             return;
//         size--;
//         if (front == rear)
//         {
//             front = rear = nullptr;
//             return;
//         }
//         node *temp = front;
//         front = front->next;
//         front->prev = nullptr;
//         delete temp;
//     }
//     void delete_from_rear()
//     {
//         if (front == nullptr and rear == nullptr)
//             return;
//         size--;
//         if (front == rear)
//         {
//             front = rear = nullptr;
//             return;
//         }
//         node *temp = rear;
//         rear = rear->prev;
//         rear->next = nullptr;
//         delete temp;
//     }
// };
// int main()
// {
//     return 0;
// }




// carefull




//{ Driver Code Starts
// Initial Template for C++

// C++ implementation of Deque using
// doubly linked list
#include <bits/stdc++.h>

using namespace std;

// Node of a doubly linked list
struct Node
{
    int data;
    Node *prev, *next;
    // Function to get a new node
    static Node *getnode(int data)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }
};

// A structure to represent a deque
class Deque
{
    Node *front;
    Node *rear;
    int Size;

public:
    Deque()
    {
        front = rear = NULL;
        Size = 0;
    }

    // Operations on Deque
    void insertFront(int data);
    void insertRear(int data);
    void deleteFront();
    void deleteRear();
    int getFront();
    int getRear();
    bool isEmpty();
};

// Function to check whether deque
// is empty or not
bool Deque::isEmpty()
{
    return (front == NULL);
}

// Function to return the element
// at the front end
int Deque::getFront()
{
    // If deque is empty, then returns
    // garbage value
    if (isEmpty())
        return -1;
    return front->data;
}

// Function to return the element
// at the rear end
int Deque::getRear()
{
    // If deque is empty, then returns
    // garbage value
    if (isEmpty())
        return -1;
    return rear->data;
}

// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    Node *prev, *next;
    // Function to get a new node
    static Node* getnode(int data)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }
};
*/

void Deque::insertFront(int value)
{
    // Your code here
    Node *newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = front;
    if (front != nullptr)
    {
        front->prev = newNode;
    }
    else
    {
        rear = newNode;
    }

    front = newNode;
    Size++;
}

// Function to insert an element
// at the rear end
void Deque::insertRear(int value)
{
    // Your code here
    Node *newNode = new Node;
    newNode->data = value;
    newNode->prev = rear;
    newNode->next = nullptr;

    if (rear != nullptr)
    {
        rear->next = newNode;
    }
    else
    {
        front = newNode;
    }

    rear = newNode;
    Size++;
}

// Function to delete the element
// from the front end
void Deque::deleteFront()
{
    // Your code here
    if (front == nullptr and rear == nullptr)
        return;
    Size--;
    if (front == rear)
    {
        front = rear = nullptr;
        return;
    }
    Node *temp = front;
    front = front->next;
    front->prev = nullptr;
    delete temp;

    // return frontValue;
}

// Function to delete the element
// from the rear end
void Deque::deleteRear()
{
    // Your code here
    if (front == nullptr and rear == nullptr)
        return;
    Size--;
    if (front == rear)
    {
        front = rear = nullptr;
        return;
    }
    Node *temp = rear;
    rear = rear->prev;
    rear->next = nullptr;
    delete temp;
}

//{ Driver Code Starts.

// Driver program to test above
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;

        Deque dq;

        while (q--)
        {

            string qt;
            cin >> qt;

            if (qt == "ir")
            {
                int data;
                cin >> data;
                dq.insertRear(data);
            }
            else if (qt == "if")
            {
                int data;
                cin >> data;
                dq.insertFront(data);
            }
            else if (qt == "dr")
            {
                dq.deleteRear();
            }
            else if (qt == "df")
            {
                dq.deleteFront();
            }
        }

        cout << dq.getFront() << endl;
        cout << dq.getRear() << endl;
    }
    return 0;
}

// } Driver Code Ends