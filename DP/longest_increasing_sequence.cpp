#include <bits/stdc++.h>
using namespace std;
class Pair
{
public:
    int i;
    string psf;
};
void LIS(vector<int> arr, int n)
{
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int mx = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                mx = max(mx, dp[j]);
            }
        }
        if (mx != INT_MIN)
            dp[i] = mx + 1;
        else if (mx == INT_MIN)
            dp[i] = 1;
    }
    int mx(-1), idx;
    for (int i = 0; i < n; i++)
    {
        if (mx < dp[i])
        {
            mx = dp[i];
            idx = i;
        }
    }
    cout << mx <<  endl;
    queue<Pair> q;
    q.push({idx, to_string(arr[idx])});
    while (!q.empty())
    {
        Pair rem = q.front();
        q.pop();

        if (rem.i == 0)
        {
            cout << rem.psf << endl;
        }
        for (int i = rem.i; i >= 0; i--)
        {
            int val = dp[rem.i];
            if (dp[i] == val - 1)
            {
                q.push({i, to_string(arr[i]) + " -> " + rem.psf});
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

    LIS(arr, n);
}
// for (int i = rem.i; i >= 0; i--)
// {
//     int val = dp[rem.i];
//     if (dp[i] == val - 1)
//     {
//         q.push({i, rem.psf + " " + to_string(arr[i])});
//     }
// }