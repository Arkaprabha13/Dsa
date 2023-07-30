#include <bits/stdc++.h>
using namespace std;
void print_greater_elements(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int counter = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i && a[j] > a[i])
            {
                counter++;
            }
        }
        cout << counter << " ";
    }
}
void efficient_solution_using_map(int *a, int n)
{
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    int cumulative_frequencies = 0;
    for (auto it = m.rbegin(); it != m.rend(); it++)
    {
        int freq = it->second;
        it->second = cumulative_frequencies;
        cumulative_frequencies += freq;
    }
    for (int i = 0; i < n; i++)
    {
        cout << m[a[i]] << " ";
    }
}
int main()
{
    int n;
    cout << "N-> ";
    cin >> n;
    cout << endl;
    int *arr = new int[n]; // Allocate memory for the array

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    print_greater_elements(arr, n);
    return 0;
}