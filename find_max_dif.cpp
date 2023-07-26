#include <bits/stdc++.h>
using namespace std;
void max_dif(int *a, int n)
{
    /* naive solution
    int result = a[1] - a[0];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            result = max(result, a[j] - a[i]);
        }
    }
    cout << result;
    */
    int result = a[1] - a[0];
    int min_value = a[0];
    for (int j = 1; j < n; j++)
    {
        result = max(result, a[j] - min_value);
        min_value = min(min_value, a[j]);
    }
    cout << endl
         << result;
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
    max_dif(a, n);
    return 0;
}