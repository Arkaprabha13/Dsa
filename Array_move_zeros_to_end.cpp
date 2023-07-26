#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void move_all_zeros_to_end(int *a, int n)
{
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[counter]);
            counter++;
        }
    }
    cout << "\nAfter moving -> ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n = 8;
    int *a = new int[n]; // Allocate memory for the array

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    move_all_zeros_to_end(a, n);

    delete[] a; // Free the allocated memory

    return 0;
}
