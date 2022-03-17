#include<bits/stdc++.h>
using namespace std;
void sol(string s1,string s2,int n,int m){
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));

    for(int i = m; i >=0 ;i--){
        for(int j = n ; j >= 0;j--){
          if(i == m){
              dp[i][j] = 0;
          }  
          else if(i == m and j == n){
              dp[i][j] = 1;
          }else if(j == n){
              if(s2[i] == '*'){
                  dp[i][j] = dp[i+1][j];
              }else {
                  dp[i][j] =0;
              }
          }
          else{
              if(s2[i] == '?'){
                  dp[i][j] = dp[i+1][j+1];
              }else if(s2[i]=='*'){
                dp[i][j] = dp[i][j+1] or dp[i+1][j];
              }
                  else if(s2[i] == s1[j]){
                      dp[i][j] = dp[i+1][j+1];
                  }else{
                      dp[i][j] = 0;
                  }
              
          }
        }
    }
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }

}
int main(){

    string s;
    getline(cin,s);
    string m;
    getline(cin,m);
    sol(s,m,s.length(),m.length());
}

