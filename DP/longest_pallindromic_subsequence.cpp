#include<bits/stdc++.h>
using namespace std;
void sol(string s,int n){

    int dp[n][n];
    for(int g = 0 ; g < n ; g++){
        for(int i = 0, j = g; i < n, j < n ; i++,j++){
            if(g==0){
                dp[i][j] = 1;
            }else if(g == 1){
                if(s[i] == s[j]){
                    dp[i][j] = 2;
                }else{
                    dp[i][j] = 1;
                }
            }else{
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1]+2;
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
    }
    cout<<dp[0][n-1];
}
int main(){
    string s;
    getline(cin,s);

    sol(s,s.length());
}