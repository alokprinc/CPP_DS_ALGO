#include <bits/stdc++.h>
using namespace std;

int longest_common_substring(string x, string y, int n, int m)
{
    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }
    int result = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if(x[i-1] == y[j-1]){
                t[i][j] = t[i-1][j-1] + 1;
                result = max(result,t[i][j]);
            }
            else{
                t[i][j] = 0;
            }
        }
    }
    return result;
}

int main()
{
    string x = "heap";
    string y = "pea";
    int n = x.size();
    int m = y.size();

    cout << longest_common_substring(x,y, n, m);
}