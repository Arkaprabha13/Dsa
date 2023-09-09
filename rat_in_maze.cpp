#include <bits/stdc++.h>
using namespace std;
bool is_safe_to_go(int source_x_coordinate, int source_y_coordinate, int row, int col, int maze[3][3], vector<vector<bool>> &visited)
{
    if ((source_x_coordinate >= 0 && source_x_coordinate < row) && (source_y_coordinate >= 0 && source_y_coordinate < col) && (maze[source_x_coordinate][source_y_coordinate] == 1) && (visited[source_x_coordinate][source_y_coordinate] == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve_maze(int maze[3][3], int row, int col, int source_x_coordinate, int source_y_coordinate, vector<vector<bool>> &visited, vector<string> &path, string output)
{
    // base case
    if (source_x_coordinate == row - 1 && source_y_coordinate == col - 1)
    {
        // answer found
        path.push_back(output);
        return;
    }
    // Down (i+1,j)
    if (is_safe_to_go(source_x_coordinate + 1, source_y_coordinate, row, col, maze, visited))
    {
        visited[source_x_coordinate + 1][source_y_coordinate] = true;
        solve_maze(maze, row, col, source_x_coordinate + 1, source_y_coordinate, visited, path, output + "D");

        // backtrack
        visited[source_x_coordinate + 1][source_y_coordinate] = false;
    }
    // up   (i-1,j)
    if (is_safe_to_go(source_x_coordinate - 1, source_y_coordinate, row, col, maze, visited))
    {
        visited[source_x_coordinate - 1][source_y_coordinate] = true;
        solve_maze(maze, row, col, source_x_coordinate - 1, source_y_coordinate, visited, path, output + "U");

        // backtrack
        visited[source_x_coordinate - 1][source_y_coordinate] = false;
    }
    // Right    (i,j+1)
    if (is_safe_to_go(source_x_coordinate, source_y_coordinate + 1, row, col, maze, visited))
    {
        visited[source_x_coordinate][source_y_coordinate + 1] = true;
        solve_maze(maze, row, col, source_x_coordinate, source_y_coordinate + 1, visited, path, output + "R");

        // backtrack
        visited[source_x_coordinate][source_y_coordinate + 1] = false;
    }
    // left (i,j-1)
    if (is_safe_to_go(source_x_coordinate, source_y_coordinate - 1, row, col, maze, visited))
    {
        visited[source_x_coordinate][source_y_coordinate - 1] = true;
        solve_maze(maze, row, col, source_x_coordinate, source_y_coordinate - 1, visited, path, output + "L");

        // backtrack
        visited[source_x_coordinate][source_y_coordinate - 1] = false;
    }
}
int main()
{
    int maze[3][3] = {{1, 0, 0},
                      {1, 1, 0},
                      {1, 1, 1}};
    if (maze[0][0] == 0)
    {
        cout << "no path exisit !!" << endl;
        return 0;
    }
    int row = 3;
    int col = 3;
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    visited[0][0] = true;
    vector<string> path;

    string output = "";

    solve_maze(maze, row, col, 0, 0, visited, path, output);
    if (path.size() == 0)
    {
        cout << "no path exisit !!" << endl;
        return 0;
    }
    cout << "The resultant direction for rat " << endl;
    for (auto i : path)
    {
        cout << i << " ";
    }
    cout << endl; 
    return 0;
}