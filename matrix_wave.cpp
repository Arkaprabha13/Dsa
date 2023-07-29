#include <bits/stdc++.h>
using namespace std;
void wave_print_matrix(vector<vector<int>> v)
{
    int m = v.size();    // row
    int n = v[0].size(); // column
    for (int start_column = 0; start_column < n; start_column++)
    {
        // even no of column-> top->bottom
        // odd no of column-> bottom->top
        if ((start_column & 1) == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << v[i][start_column]<<" ";
            }
        }
        else
        {
            for (int i = m - 1; i >= 0; i--)
            {
                cout << v[i][start_column]<<" ";
            }
        }
    }
}
int main()
{
    int n, m;
    cout << "N-> ";
    cin >> n;
    cout << "M-> ";
    cin >> m;
    vector<vector<int>> v;
    v.resize(m);
    for (int i = 0; i < m; i++)
    {
        v[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cout << i << " , " << j << " -> ";
            cin >> v[i][j];
            // v.push_back(a[i][j]);
        }
    }
    wave_print_matrix(v);
    return 0;
}