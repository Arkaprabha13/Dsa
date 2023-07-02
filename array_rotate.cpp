#include <bits/stdc++.h>
using namespace std;
void left_rotate_an_array(int arr[],int n,int d)
{
    int p=1;
    while(p<=d)
    {
        int last=arr[0];
        for (int i = 1; i < n; i++)
        {
            arr[i-1]=arr[i];
        }
        arr[n-1]=last;
        p++;
        
    }
}
int main()
{
    int n,d;
    cout<<"n : ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] : ";
        cin >> arr[i];
    }
    cout<<" d : ";
    cin>>d;
    left_rotate_an_array(arr,n,d);
    for (int i = 0; i < n; i++)
    {
    cout<<arr[i];
    }
    
    return 0;
}