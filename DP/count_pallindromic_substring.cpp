#include <bits/stdc++.h>
using namespace std;
void sol(string s, int n)
{
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    int count = 0;
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; i < n, j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = 1;
                count++;
            }
            else if (g == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 1;
                    count++;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else
            {
                if (s[i] == s[j] and dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    count++;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    int sm=0;
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; i < n, j < n; i++, j++)
        {
            if(dp[i][j]== 1 and j-i+1 > sm){
                sm = j-i+1;
            }
        }
    }
    cout << count<<endl;
}
int main()
{
    string s;
    getline(cin, s);

    sol(s, s.length());
}