#include <bits/stdc++.h>
using namespace std;

int main()
{
    // fixed sized arrays
    cout << "\n fixed sized arrays  \n";
    int arr[3][2] = {{10, 20},
                     {30, 40},
                     {50, 60}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
    }

    // varriable sized arrays
    cout << "\nvarriable sized arrays ->  \n";
    int m2 = 3, n2 = 2;
    int arr2[m2][n2];

    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            arr2[i][j] = i + j;
        }
    }

    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << arr2[i][j] << " ";
        }
    }
    // double pointer
    cout << "\ndouble pointer -> \n";
    int m100 = 3, n100 = 2;
    int **arr100;

    arr100 = new int *[m100];

    for (int i = 0; i < m100; i++)
        arr100[i] = new int[n100];

    for (int i = 0; i < m100; i++)
    {
        for (int j = 0; j < n100; j++)
        {
            arr100[i][j] = 10;

            cout << arr100[i][j] << " ";
        }
    }
    // array of pointer
    cout << "\n array of pointer  -> \n";

    int m3 = 3, n3 = 2;

    int *arr3[m3];

    for (int i = 0; i < m3; i++)
        arr3[i] = new int[n3];

    for (int i = 0; i < m3; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            arr3[i][j] = 10;

            cout << arr3[i][j] << " ";
        }
    }
    // array of vectors
    cout << "\narray of vectors : \n";
    int m4 = 3, n4 = 2;

    vector<int> arr4[m4];

    for (int i = 0; i < m4; i++)
    {
        for (int j = 0; j < n4; j++)
        {
            arr4[i].push_back(10);
        }
    }

    for (int i = 0; i < m4; i++)
    {
        for (int j = 0; j < n4; j++)
        {
            cout << arr4[i][j] << " ";
        }
    }
    // vector of vectorsd :
    cout << "\nvector of vectors -> \n";
    int m5 = 3, n5 = 2;

    vector<vector<int>> arr5;

    for (int i = 0; i < m5; i++)
    {
        vector<int> v;

        for (int j = 0; j < n5; j++)
        {
            v.push_back(10);
        }

        arr5.push_back(v);
    }

    for (int i = 0; i < arr5.size(); i++)
    {
        for (int j = 0; j < arr5[i].size(); j++)
        {
            cout << arr5[i][j] << " ";
        }
    }
    return 0;
}