#include <iostream>
using namespace std;

bool isSafe(int **board, int x, int y, int n)
{
    int i,j;

    for ( i = 0; i < x; i++){
        if (board[i][y] == 1){
            return false;
        }
    }
i = x;
j = y;
while (i>=0 && j >= 0){
    if (board[i][j] == 1){
        return false;
    }
    i--;
    j--;
}
i = x;
j = y;
while (i>=0 && j < n)
{
    if (board[i][j] == 1)
    {
        return false;
    }
    i--;j++;
}

    
    return true;
}

bool nQueen(int **board, int x,int n)
{

    if (x >= n)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, x, i, n))
        {
            board[x][i] = 1;

            if (nQueen(board, x+1, n)){
                return true;
            }
            board[x][i] = 0; // backtracking
        }
        
    }
    return false;
}

int main()
{

    int n;
    cin >> n;

    int **board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    
    if (nQueen(board, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
}