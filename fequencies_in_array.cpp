#include <bits/stdc++.h>
using namespace std;

void frequencies_in_array(int *a, int n)
{
    int freq = 1;
    int i = 1;
    while (i < n)
    {
        while (i < n && a[i] == a[i - 1])
        {
            freq++;
            i++;
        }
        cout << a[i - 1] << " " << freq << endl;
        i++;
        freq = 1;
    }
    if (n == 1 && a[i] != a[i - 1])
    {
        cout << a[n - 1] << " ";
    }
}
int main()
{
    int n;
    cout << "N-> ";
    cin >> n;
    cout << endl;
    int *a = new int[n]; // Allocate memory for the array

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    frequencies_in_array(a, n);
    return 0;
}