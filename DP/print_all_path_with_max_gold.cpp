#include <bits/stdc++.h>
using namespace std;
class Pair
{
public:
    int i;
    int j;
    string psf;
};
void sol(vector<vector<int>> &arr, int n, int m)
{
    int dp[n][m];

    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (j == m - 1)
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = arr[i][j] + max(dp[i + 1][j + 1], dp[i][j + 1]);
            }
            else if (i == n - 1)
            {
                dp[i][j] = arr[i][j] + max(dp[i - 1][j + 1], dp[i][j + 1]);
            }
            else
            {
                dp[i][j] = arr[i][j] + max(max(dp[i + 1][j + 1], dp[i][j + 1]), dp[i - 1][j + 1]);
            }
        }
    }
    int mx = INT_MIN;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (dp[i][0] > mx)
        {
            mx = dp[i][0];
            idx = i;
        }
    }
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0; j < m; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
    cout << mx << endl;
    

    queue<Pair> q;
    q.push({idx, 0, ""});

    while (!q.empty())
    {
        Pair rem = q.front();
        q.pop();

        if (rem.j == m - 1)
        {
            cout << idx;
            cout << rem.psf << endl;
        }
        else if (rem.i == 0)
        {
            int umx = max(dp[rem.i][rem.j + 1], dp[rem.i + 1][rem.j + 1]);
            if (umx == dp[rem.i][rem.j + 1])
            {
                q.push({rem.i, rem.j + 1, rem.psf + " d2"});
            }
            if (umx == dp[rem.i + 1][rem.j + 1])
            {
                q.push({rem.i + 1, rem.j + 1, rem.psf + " d3"});
            }
        }
        else if (rem.i == n - 1)
        {
            int umx = max(dp[rem.i][rem.j + 1], dp[rem.i - 1][rem.j + 1]);
            if (umx == dp[rem.i - 1][rem.j + 1])
            {
                q.push({rem.i - 1, rem.j + 1, rem.psf + " d1"});
            }
            if (umx == dp[rem.i][rem.j + 1])
            {
                q.push({rem.i, rem.j + 1, rem.psf + " d2"});
            }
            
        }
        else
        {
            int umx = max(max(dp[rem.i][rem.j + 1], dp[rem.i + 1][rem.j + 1]), dp[rem.i - 1][rem.j + 1]);
            if (umx == dp[rem.i - 1][rem.j + 1]){
                q.push({rem.i - 1, rem.j + 1, rem.psf + " d1"});
            }
            if (umx == dp[rem.i][rem.j + 1])
            {
                q.push({rem.i, rem.j + 1, rem.psf + " d2"});
            }
            if (umx == dp[rem.i + 1][rem.j + 1])
            {
                q.push({rem.i + 1, rem.j + 1, rem.psf + " d3"});
            }
            
            
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // for(auto a: arr){
    //     for(auto b:a){
    //         cout<<b<<" ";
    //     }cout<<endl;
    // }

    sol(arr, n, m);
}