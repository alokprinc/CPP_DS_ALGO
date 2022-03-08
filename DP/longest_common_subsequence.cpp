#include <bits/stdc++.h>
using namespace std;
void sol(string s1,string s2){
    int n = s1.length();
    int m = s2.length();

    int dp[n+1][m+1];
   // memset(dp,0,sizeof(dp));
    for(int i = n;i >=0; i--){
        for(int j = m; j >=0; j--){
            if(i == n){
                dp[i][j] = 0;
            }else if(j == m){
                dp[i][j] = 0;
            }else{
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i+1][j+1]+1;
                }else {
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }

    }
    
        // for(int i = 0 ; i < n+1; i++){
        //     for(int j = 0 ; j < m+1 ; j++){
        //         cout<<dp[i][j]<<" ";

        //     }cout<<endl;
        // }
        cout<<dp[0][0];
}
int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    sol(s1, s2);
}