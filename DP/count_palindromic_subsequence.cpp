#include<bits/stdc++.h>
using namespace std;
void sol(string s,int n){
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int g = 0 ; g < n ; g++){
        for(int i = 0, j  = g; i < n , j < n;i++,j++){
            if(g == 0){
                dp[i][j] = 1;
            }
            else if(g == 1){
                    dp[i][j] = s[i] == s[j]? 3: 2; 
                }
            else{
                if(s[i]==s[j]){
                    dp[i][j] = dp[i][j-1]+dp[i+1][j]+1;
                }else {
                    dp[i][j] = dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ;j++){
            cout<< dp[i][j]<<" ";
        }cout<<endl;
    }
}
int main(){
    string s;
    getline(cin,s);

    sol(s,s.length());
}