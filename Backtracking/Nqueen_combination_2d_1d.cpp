#include <bits/stdc++.h>
using namespace std;

bool isSafe(int r, int c, int n, vector<vector<int>> chess)
{
    // up
    for (int i = r-1, j = c; i >= 0; i--)
    {
        if (chess[i][j] > 0)
        {
            return false;
        }
    }
    // ul
    for (int i = r-1, j = c-1; i >= 0 and j >= 0; i--, j--)
    {
        if (chess[i][j] > 0)
        {
            return false;
        }
    } // ur
    for (int i = r-1, j = c+1; i >= 0 and j < n; i--, j++)
    {
        if (chess[i][j] > 0)
        {
            return false;
        }
    } // l
    for (int i = r, j = c-1;  j >= 0; j--)
    {
        if (chess[i][j] > 0)
        {
            return false;
        }
    }
    return true;
}
void nqueen(vector<vector<int>> chess, int qsf, int n,int lVal)
{
    if (qsf ==  n)
    {
        for (auto a : chess)
        {
            for (auto b : a)
            {
                if (b > 0)
                {
                    cout << "q\t";
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
    for (int i = lVal+1; i < n * n; i++)
    {
        int row = i / n;
        int col = i % n;

        if (isSafe(row, col, n, chess))
        {

            chess[row][col] = qsf + 1;
            nqueen(chess, qsf + 1, n,i);
            chess[row][col] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> chess(n, vector<int>(n, 0));
    nqueen(chess, 0, n,-1);
}