#include <bits/stdc++.h>
using namespace std;
void isPalindrome(string s, int n)
{
    int dp[n][n];
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; i < n, j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = 1;
            }
            else if (g == 1)
            {
                dp[i][j] = s[i] == s[j] ? 1 : 0;
            }
            else
            {
                if (s[i] == s[j] and dp[i + 1][j - 1])
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
   
   int dp2[n];
   dp2[0]=0;
   for(int j = 1;j<n;j++){
       if(dp[0][j]){
           dp2[j]=0;
       }else{
           int mn = INT_MAX;
           for(int i=j;i>=1;i--){
               if(dp[i][j])
               mn = min(mn,dp[i-1]);
           }
       }
   }
}
int main()
{
    string s;
    getline(cin, s);

    isPalindrome(s, s.length());
}