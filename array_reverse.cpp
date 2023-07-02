#include<bits/stdc++.h>
using namespace std;
void reverse(int a[],int n)
{

    for (int i = 0; i < n/2; i++)
    {
        if(a[i]>a[i+1])
        {
           swap(a[i],a[i+1]);
        }
    }
    

}
int main()
{
    int a[5]={8,1,81,25,6};
    reverse(a,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<a[i]<<" ";
    }
    

return 0;
}