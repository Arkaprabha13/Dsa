#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> create_matrix(int r, int c)
{
    vector<vector<int>> matrix;
    for (int i = 0; i < r; i++)
    {
        vector<int> v;
        for (int j = 0; j < c; j++)
        {
            cout << "[" << i << "][" << j << "] -> ";
            // cin >> matrix;
            int k;
            cin >> k;
            v.push_back(k);
        }
        matrix.push_back(v);
    }
    return matrix;
}
void display(vector<vector<int>> v, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
void print_snake(vector<vector<int>> v, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < c; j++)
            {
                cout << v[i][j] << " ";
            }
        }
        else
        {
            for (int j = c - 1; j >= 0; j--)
            {
                cout << v[i][j] << " ";
            }
        }
    }
}
int main()
{
    int r, c;
    cout << "ENter row-> ";
    cin >> r;
    cout << "ENter column-> ";
    cin >> c;
    vector<vector<int>> v;
    v = create_matrix(r, c);
    display(v, r, c);
    print_snake(v, r, c);

    return 0;
}