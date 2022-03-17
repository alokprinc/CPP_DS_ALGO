#include <bits/stdc++.h>
using namespace std;
void sol(string s, int n)
{
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    vector<int> pre(n, 0);
    unordered_map<char, int> mp;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(s[i]) == mp.end())
        {
            pre[i] = -1;
            mp.insert({s[i], i});
        }
        else
        {
            pre[i] = mp[s[i]];
            mp[s[i]] = i;
        }
       
    }
    vector<int> nxt(n, 0);
    unordered_map<char, int> mp2;
    // for(auto a:pre){
    //     cout<<a<<" ";
    // }cout<<endl;
    for (int i = n - 1; i >= 0; i--)
    {
        if (mp2.find(s[i]) == mp2.end())
        {
            nxt[i] = -1;
            mp2.insert({s[i], i});
        }
        else
        {
            nxt[i] = mp2[s[i]];
            mp2[s[i]] = i;
        }
        
    }
// for(auto a:nxt){
//         cout<<a<<" ";
//     }cout<<endl;
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g;  j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = 1;
            }
            else if (g == 1)
            {
                dp[i][j] = 2;
            }
            else
            {
                if (s[i] != s[j])
                {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
                else
                {
                   int nx = nxt[i];
                   int pr = pre[j];
                   if(nx > pr){
                       dp[i][j] = 2*dp[i+1][j-1]+2;
                   }else if(nx == pr){
                       dp[i][j] = 2*dp[i+1][j-1]+1;
                   }else {
                       dp[i][j] = 2*dp[i+1][j-1]-dp[nx+1][pr-1];
                   }
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
}
int main()
{
    string s;
    getline(cin, s);
    sol(s, s.length());
}