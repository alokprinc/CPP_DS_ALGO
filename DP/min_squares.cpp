#include<bits/stdc++.h>
using namespace std;
void sol(int n){
    int dp[n+1];
 dp[0] = 0;
 dp[1] = 1;
    for(int i = 2 ; i < n+1; i++){
        int mn = INT_MAX;
        for(int j = 1; j*j<=i;j++){
            mn = min(mn,dp[i-j*j]);
        }
        if(mn != INT_MAX)
            dp[i] = mn+1;
        else
            dp[i] = 1;
    }

    // for(int i = 0 ; i < n+1 ; i++){
    //     cout<<dp[i]<<" ";
    // }
    cout<<dp[n];
}
int main(){
    int n;
    cin>>n;

    sol(n);
}