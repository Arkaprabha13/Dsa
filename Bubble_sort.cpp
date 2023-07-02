#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        // Your code here  
        // for(int i=1;i<n;i++)
        // {
        //     for(int j=0;j<n-i;j++)
        //     {
        //         if(arr[j]>arr[j+1])
        //         {
        //             swap(arr[j],arr[j+1]);
        //         }
        //     }
        // }
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
};
void printArray(int arr[],int  size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i];
    }
}
int main()
{
    int a[1000],n,T,i;
    cin>>T;
    while (T--)
    {
        /* code */
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        Solution ob;
        ob.bubbleSort(a,n);
        printArray(a,n);
    }
    
return 0;
}