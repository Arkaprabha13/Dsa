#include <bits/stdc++.h>
using namespace std;
int max_of_1s(int *a, int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int counter = 0;
        for (int j = i; j < n; j++)
        {
            if (a[j] == 1)
            {
                counter++;
            }
            else
            {
                break;
            }
        }
        result = max(result, counter);
    }
    return result;
}
int efficeient_filter(int *a,int n)
{
    
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
    int a = max_of_1s(arr, n);
    cout << "The ans is -> " << a << endl;
    return 0;
}