#include <bits/stdc++.h>
using namespace std;
class Pair
{
public:
    int i;
    int j;
    string psf;
};
void knapsack(vector<int> &items, vector<int> &weight, int n, int bag)
{
    int dp[n + 1][bag + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < bag + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (j >= weight[i - 1])
                {
                    dp[i][j] = max(items[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    cout << dp[n][bag] << endl;
    // for(int i = 0 ; i < n+1 ; i++){
    //     for(int j = 0 ; j < bag +1 ; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
    queue<Pair> q;
    q.push({n, bag, ""});
    while (!q.empty())
    {
        Pair rem = q.front();
        q.pop();
        if (rem.i == 0 || rem.j == 0)
        {
            cout << rem.psf << endl;
        }
        else
        {
           
            if (rem.j >= weight[rem.i - 1])
            {
                int inc = dp[rem.i - 1][rem.j - weight[rem.i - 1]]+items[rem.i-1];
                if (inc == dp[rem.i][rem.j])
                {
                    q.push({rem.i - 1, rem.j - weight[rem.i - 1],to_string(rem.i - 1)+" "+rem.psf});
                }
            }
            int exc = dp[rem.i - 1][rem.j];
            if (exc == dp[rem.i][rem.j])
            {
                q.push({rem.i - 1, rem.j, rem.psf});
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
        // cout<<items[i];
    }
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        // cout<<weight[i];
    }
    int bag;
    cin >> bag;
    knapsack(items, weight, n, bag);
}