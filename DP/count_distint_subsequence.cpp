#include <bits/stdc++.h>
using namespace std;
void sol(string s, int n)
{
    // long long dp[n + 1];
    long long int dp[n+1];
   
    dp[0] = 1;
    unordered_map<char, int> mp;
    for (int i = 1; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] * 2;
        if (mp.find(s[i - 1]) != mp.end())
        {
            dp[i] = dp[i] - dp[mp[s[i - 1] - 1]];
        }

        mp.insert({s[i - 1], i});
    }
    for(int i = 0 ; i < n+1; i++){
        cout<<dp[i]<<" ";
    }
    cout << dp[n] - 1;
}
int main()
{
    string s;
    getline(cin, s);

    sol(s, s.length());
}