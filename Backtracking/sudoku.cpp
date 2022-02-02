#include <bits/stdc++.h>
using namespace std;
void disp(vector<vector<int>> board)
{
    for (auto a : board)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
}
bool isValid(vector<vector<int>> board, int r, int c, int val)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][c] == val)
        {
            return false;
        }
    }
    for (int i = 0; i < board.size(); i++)
    {
        if (board[r][i] == val)
        {
            return false;
        }
    }

    int subMatrix_i = (r / 3) * 3;
    int subMatrix_j = (c / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[subMatrix_i + i][subMatrix_j + j] == val)
            {
                return false;
            }
        }
    }
    return true;
}

void sudoku(vector<vector<int>> board, int r, int c)
{
    if (r == board.size())
    {
        disp(board);
        return;
    }
    int nr = 0;
    int nc = 0;
    if (c == board[0].size() - 1)
    {
        nr = r + 1;
        nc = 0;
    }
    else
    {
        nr = r;
        nc = c + 1;
    }

    if (board[r][c] != 0)
    {
        sudoku(board, nr, nc);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (isValid(board, r, c, i))
            {
                board[r][c] = i;
                sudoku(board, nr, nc);
                board[r][c] = 0;
            }
        }
    }
}
int main()
{
    vector<vector<int>> arr(9, vector<int>(9));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
        }
    }

    sudoku(arr, 0, 0);
}
