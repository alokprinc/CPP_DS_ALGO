#include <bits/stdc++.h>
using namespace std;

bool isSafe(int r, int c, int n, vector<vector<int>> chess)
{
    // up
    for (int i = r, j = c; i >= 0; i--)
    {
        if (chess[i][j] > 0)
        {
            return false;
        }
    }
    // d
    for (int i = r, j = c; i < n; i++)
    {
        if (chess[i][j] > 0)
        {
            return false;
        }
    }
    ///r
    for (int i = r, j = c ; j < n; j++)
    {
        if (chess[i][j] >0)
        {
            return false;
        }
    }
    // l
    for (int i = r, j = c ; j >= 0; j--)
    {
        if (chess[i][j] > 0)
        {
            return false;
        }
    }
    // ul
    for (int i = r, j = c; i >= 0 and j >= 0; i--, j--)
    {
        if (chess[i][j] > 0)
        {
            return false;
        }
    } // ur
    for (int i = r, j = c; i >= 0 and j < n; i--, j++)
    {
        if (chess[i][j] > 0)
        {
            return false;
        }
    } // ll
    for (int i = r , j = c; i < n and j >= 0; i++, j--)
    {
        if (chess[i][j] > 0)
        {
            return false;
        }
        // lr
    }
    for (int i = r , j = c; i < n and j < n; i++, j++)
    {
        if (chess[i][j] > 0)
        {
            return false;
        }
    }
    
    return true;
}
void nqueen(vector<vector<int>> chess, int qsf, int n)
{
    if (qsf==  n)
    {
        for (auto a : chess)
        {
            for (auto b : a)
            {
                if (b > 0)
                {
                    cout << "q" << b << "\t";
                }
                else
                {
                    cout << "-\t";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n * n; i++)
    {
        int row = i / n;
        int col = i % n;

        if (chess[row][col] == 0 and isSafe(row, col, n, chess))
        {

            chess[row][col] = qsf + 1;
            nqueen(chess, qsf + 1, n);
            chess[row][col] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> chess(n, vector<int>(n, 0));
    nqueen(chess, 0, n);
}