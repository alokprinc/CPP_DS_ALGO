#include <bits/stdc++.h>
using namespace std;
void disp(vector<vector<char>> board)
{
    for (auto a : board)
    {
        for (auto b : a)
        {
            cout << b;
        }
        cout << endl;
    }cout << endl;
}
bool isperfectFitHorizontaly(string word, int i, int j, vector<vector<char>> board)
{   
    if (j - 1 >= 0 and board[i][j - 1] != '+')
    {
        return false;
    }
    else if (j + word.length() < board[0].size() and board[i][j + word.length()] != '+')
    {
        return false;
    }
    // if we reach here we are perfect fit

    for (int jj = 0; jj < word.length(); jj++)
    {
        if (j + jj >= board[0].size())
        {
            return false;
        }
        if (board[i][j+jj] == '-' or board[i][j+jj] == word[jj])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool isperfectFitVerticaly(string word, int i, int j, vector<vector<char>> board)
{ 
    if (i - 1 >= 0 and board[i - 1][j] != '+')
    {
        return false;
    }
    else if (i + word.length() < board.size() and board[i + word.length()][j] != '+')
    {
        return false;
    }
    // if we reach here we are perfect fit

    for (int ii = 0; ii < word.length(); ii++)
    {
        if (i + ii >= board.size())
        {
            return false;
        }
        if (board[i+ii][j] == '-' or board[i+ii][j] == word[ii])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
vector<int> placeHorizontaly(string word, int i, int j, vector<vector<char>> &board)
{
    vector<int> check(word.length(),0);

    for (int jj = 0; jj < word.length(); jj++)
    {
        if (board[i][j+jj] == '-' )
        {   
            board[i][j+jj] = word[jj];
            check[jj] = 1;
        }
    }
    return check;
}
void removeHorizontaly(string word, int i, int j, vector<vector<char>> &board, vector<int> check)
{

    for (int jj = 0; jj < check.size(); jj++)
    {
        if (check[jj] == 1)
        {
            board[i][j+jj] = '-';
        }
    }
}
vector<int> placeVerticaly(string word, int i, int j, vector<vector<char>> &board)
{
    vector<int> check(word.length(),0);

    for (int ii = 0; ii < word.length(); ii++)
    {
        if (board[i+ii][j] == '-' )
        {   
            board[i+ii][j] = word[ii];
            check[ii] = 1;
        }
    }
    return check;
}

void removeVerticaly(string word, int i, int j, vector<vector<char>> &board, vector<int> check)
{

    for (int ii = 0; ii < check.size(); ii++)
    {
        if (check[ii] == 1)
        {
            board[i+ii][j] = '-';
        }
    }
}

void solve(vector<vector<char>> board, vector<string> words, int idx)
{
    if (idx == words.size())
    {
        disp(board);
        return;
    }
    string word = words[idx];
    for (int i = 0; i < board.size(); i++)
    {
        
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == '-' or board[i][j] == word[0])
            {
                if(isperfectFitHorizontaly(word, i, j, board))
                {   
                    
                    vector<int> check = placeHorizontaly(word, i, j, board); 
                    solve(board, words, idx + 1); 
                    removeHorizontaly(word, i, j, board, check);
                }
                else if(isperfectFitVerticaly(word, i, j, board))
                {  
                    vector<int> check = placeVerticaly(word, i, j, board);
                    solve(board, words, idx + 1);
                    removeVerticaly(word, i, j, board, check);
                }
            }
        }
    }
}
int main()
{
    vector<vector<char>> board(10, vector<char>(10));
    for (int i = 0 ; i < 10;i++)
    {
        for (int j = 0 ; j < 10; j++)
        {
            cin >> board[i][j];
        }
    }

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
  
    solve(board, words, 0);
}