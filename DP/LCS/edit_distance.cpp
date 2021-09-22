#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string p)
{
  int n = s.size();
  int m = p.size();

  int t[n + 1][m + 1];

  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < m + 1; j++)
    {
      if (i == 0)
      {
        t[i][j] = j;
      }
      else if (j == 0)
      {
        t[i][j] = i;
      }
      else if (s[i - 1] == p[j - 1])
      {
        t[i][j] = t[i - 1][j - 1];
      }
      else
      {
        t[i][j] = 1 + min(
                          min(t[i][j - 1],//insert
                          t[i - 1][j]),//remove
                          t[i - 1][j - 1]);//replace
      }
    }
  }
  return t[n][m];
}

int main()
{

  string x = "ecfbefdcfca";

  string y = "badfcbebbf";

  cout << editDistance(x, y);
}