#include <bits/stdc++.h>
using namespace std;
void sort_char(int a[], char b[], int n)
{
    pair<int, char> p[n];
        for (int i = 0; i < n; i++)
        {
            p[i] = {a[i], b[i]};
            // or p[i].first=a[i]
            // or p[i].second=b[i]
        }
    sort(p, p + n);
    cout << " 2nd part of pair --------- ";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].second << " ";
    }
}
int main()
{

    /*
        a[]={1,3,6};
        b[]={'a','z','d'};

        pairing a and b by using curly bracket only {a[i],b[i]}

        paired array={(1,'a'),(3,'z'),(6,'d')}


    */
    int a[] = {2, 1, 5, 4, 8, 3, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    char b[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
    sort_char(a, b, n);
    return 0;
}