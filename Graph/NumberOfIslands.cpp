#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vpii vector<pii>
#define lpf(i, a, b) for (int i = a; i < b; i++)
#define lpb(i, b, a) for (int i = b; i >= a; i--)
#define ff first
#define ss Second
const int N = 10e6;

void sol(vvi &vis, int i, int j, vvi arr)
{
  if (i < 0 || j < 0 || i >= arr.size() || j >= arr[i].size() || vis[i][j] == 1 || arr[i][j] == 1)
  {
    return;
  }
  vis[i][j] = 1;

  sol(vis, i, j + 1, arr);
  sol(vis, i, j - 1, arr);
  sol(vis, i + 1, j, arr);
  sol(vis, i - 1, j, arr);
}

int main()
{
  int n, m;
  cin >> n;
  cin >> m;

  vector<vector<int>> arr;

  for (int i = 0; i < n; i++)
  {
    vector<int> ans;
    for (int j = 0; j < m; j++)
    {
      int res;
      cin >> res;
      ans.push_back(res);
    }
    arr.push_back(ans);
  }
  vvi vis(n, vi(m, 0));
  int numberOfislands = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = 0; j < arr[i].size(); j++)
    {
      if (arr[i][j] == 0 && !vis[i][j])
      {
        sol(vis, i, j, arr);
        numberOfislands++;
      }
    }
  }
  cout << numberOfislands;
}