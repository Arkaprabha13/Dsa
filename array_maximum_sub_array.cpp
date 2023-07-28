#include<bits/stdc++.h>
using namespace std;
int max_sum(int *a,int n)
{
    int result=a[0];
    for(int i=0;i<n;i++)
    {
        int currennt=0;
        for(int j=i;j<n;j++)
        {
            currennt+=a[j];
            result=max(result,currennt);
        }
    }
    return result;
}
int efficient_solution(int *a,int n)
{
    int result=a[0];
    int max_end=a[0];
    for(int i=1;i<n;i++)
    {
        max_end=max(max_end+a[i],a[i]);
        result=max(result,max_end);
    }
    return result;
}
int main()
{int n;
    cout << "N-> ";
    cin >> n;
    cout << endl;
    int *a = new int[n]; // Allocate memory for the array

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
	int res=max_sum(a,n);
	cout<<res<<"\n";
return 0;
}