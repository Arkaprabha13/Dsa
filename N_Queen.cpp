/*
    1 -> Queen at cell
    0 ->  Empty cell
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> row_check;
unordered_map<int, bool> upper_right_diagonal_check;
unordered_map<int, bool> bottom_left_diagonal_check;

bool is_safe_for_unordered_map(int row, int col, vector<vector<char>> &board, int n)
{
    if (row_check[row] == true)
    {
        return false;
    }
    if (upper_right_diagonal_check[n - 1 + col - row] == true)
    {
        return false;
    }
    if (bottom_left_diagonal_check[row+col] == true)
    {
        return false;
    }
    return true;
}
bool is_it_safe_here_to_place_the_queen(int row, int col, vector<vector<char>> &board, int n)
{
    // check row
    int i = row;
    int j = col;
    while (j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false; // queen is present in that row
        }
        j--;
    }
    // check upper left diagonal
    i = row;
    j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false; // queen is present in that left diagonal
        }
        j--;
        i--;
    }
    // check bottom right diagonal
    i = row;
    j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false; // queen is present in that left diagonal
        }
        j--;
        i++;
    }

    // no objection for placing qqueen
    return true;
}
void print_solution(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
void solve_board(vector<vector<char>> &board, int col, int n)
{
    // base case
    if (col >= n)
    {
        print_solution(board, n);
        return;
    }

    // 1ta case nije korte hbe baki recursion bujhe nebe
    for (int row = 0; row < n; row++)
    {
        // for time complexity of is safe function O(n)
        // if (is_it_safe_here_to_place_the_queen(row, col, board, n))
        // {
        //     board[row][col] = 'Q';

        //     // 1st case solved now time for recursion
        //     solve_board(board, col + 1, n);
        //     board[row][col] = '-';
        // }
        // if using unordered_map then use the bellow if condition for TC O(1)
        if (is_safe_for_unordered_map(row, col, board, n))
        {
            board[row][col] = 'Q';
            row_check[row] = true;
            upper_right_diagonal_check[n - 1 + col - row] = true;
            bottom_left_diagonal_check[col + row] = true;

            // 1st case solved now time for recursion
            solve_board(board, col + 1, n);
            board[row][col] = '-';
            row_check[row] = false;
            upper_right_diagonal_check[n - 1 + col - row] = false;
            bottom_left_diagonal_check[col + row] = false;
        }
    }
}
int main()
{
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;
    solve_board(board, col, n);
    return 0;
}