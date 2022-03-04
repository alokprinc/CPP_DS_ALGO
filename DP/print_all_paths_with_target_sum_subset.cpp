#include <bits/stdc++.h>
using namespace std;
class Pair
{
public:
    int i;
    int j;
    string psf;
};
void targetsum(vector<int> &arr, int sum, int n)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] or dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    cout << (dp[n][sum]?"true":"false") << endl;
       for(int i = 0 ; i < n+1; i++){
           for(int j = 0 ; j < sum+1; j++){
               cout<<dp[i][j]<<" ";
           }cout<<endl;
       }
    queue<Pair> q;
    q.push({n, sum, ""});

    while (!q.empty())
    {
        Pair rem = q.front();
        q.pop();
    // cout<<rem.j<<" "<<rem.i<<endl;
        if (rem.i == 0 || rem.j == 0)
        {
            cout << rem.psf << endl;
        }
        else
        {
            if (rem.j >= arr[rem.i - 1])
            {
                bool inc = dp[rem.i - 1][rem.j - arr[rem.i - 1]];
                if(inc){
                q.push({rem.i - 1, rem.j - arr[rem.i - 1],to_string(rem.i - 1) +" "+rem.psf});
                }
            }
            bool exc = dp[rem.i - 1][rem.j];
            if (exc)
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

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    targetsum(arr, sum, n);
}