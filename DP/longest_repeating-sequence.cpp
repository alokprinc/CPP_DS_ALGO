#include<bits/stdc++.h>
using namespace std;
void sol(string s,int n){

    int dp[n+1][n+1];

    for(int i = n ; i >= 0; i--){
        for(int j = n; j >= 0;j--){
            if(i == n || j == n){
                dp[i][j] = 0;
            }else if(s[i] == s[j] and i != j){
                dp[i][j] = dp[i+1][j+1]+1;
            }else{
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    cout<<dp[0][0];
}
int main(){
    string s;
    getline(cin,s);
    sol(s,s.length());
}