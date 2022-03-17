#include<bits/stdc++.h>
using namespace std;
void sol(int n){
    int dp[n+1];
    dp[0] = 1;
    int i = 1, j = 1, k = 1,it = 1;
    while(it < n+1){
       // cout<<dp[i-1]<<" "<<i<<" "<<j<<" "<< k<<" "<<endl;
        int a = 2*dp[i-1];
        int b = 3*dp[j-1];
        int c = 5*dp[k-1];
        int mn = min(a,min(b,c));
        dp[it] = mn;
        if(dp[i-1]*2 == mn){
            
            i++;
        }
        if(dp[j-1]*3 == mn){
            
            j++;
        }
        if(dp[k-1]*5 == mn){
            
            k++;
        }
        it++;
    }
    cout<<dp[n-1];
}
int main(){
    int n; cin>>n;
    sol(n);
}