#include <bits/stdc++.h>
using namespace std;
int sol(string s1,string s2,int n,int m){
    int dp[n+1][m+1];

    for(int i = 0 ; i < n+1; i++){
        for(int j = 0 ;j < m+1;j++){
            if(i == 0){
                dp[i][j] = j;
            }else if(j == 0){
                dp[i][j] = i;
            }else{
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+ min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
    }
    return dp[n][m];
}
int main()
{

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout<<sol(s1,s2,s1.length(),s2.length());
}