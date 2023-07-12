// #include <bits/stdc++.h>
// using namespace std;
// struct MYstack
// {
//     int *arr;
//     int cap; // capacity
//     int top;
//     MYstack(int c)
//     {
//         cap = c;
//         arr = new int[cap];
//         top = -1;
//     }
//     void push(int x)
//     {
//         if (top == cap - 1)
//         {
//             cout << "Stack is full" << endl;
//             return;
//         }
//         top++;
//         arr[top] = x;
//     }
//     int pop()
//     {
//         if (top == -1)
//         {
//             cout << "Stack is Empty" << endl;
//             return INT_MIN;
//         }
//         int result = arr[top];
//         top--;
//         return result;
//     }
//     int peek()
//     {
//         if (top == -1)
//         {
//             cout << "Stack is Empty" << endl;
//             return INT_MIN;
//         }
//         return arr[top];
//     }
//     int size()
//     {
//         return (top + 1);
//     }
//     bool isEmpty()
//     {
//         return (top == -1);
//     }
// };
// int main()
// {
//     MYstack s(5);
//     s.push(5);
//     s.push(10);
//     s.push(20);
//     cout << s.pop() << endl;
//     cout << s.size() << endl;
//     cout << s.peek() << endl;
//     cout << s.isEmpty() << endl;

//     return 0;
// }

//              Vector form

#include <bits/stdc++.h>
using namespace std;

struct MyStack
{
    vector<int> v;

    void push(int x)
    {
        v.push_back(x);
    }

    int pop()
    {
        int res = v.back();
        v.pop_back();
        return res;
    }

    int peek()
    {
        return v.back();
    }

    int size()
    {
        return v.size();
    }

    bool isEmpty()
    {
        return v.empty();
    }
};

int main()
{
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}
