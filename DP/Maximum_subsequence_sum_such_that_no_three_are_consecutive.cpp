#include<bits/stdc++.h>
using namespace std;
int dp[1000000];

int solve(int a[],int n){
    int dp[n] ={0};
    dp[0] = a[0];
    dp[1] = a[0] + a[1];
    dp[2] = max({ a[0] + a[1], a[2] + a[1], a[0] + a[2]});

    for(int i = 3; i< n; ++i){
        dp[i] = max({dp[i-1],dp[i-2] + a[i], dp[i-3] +  a[i-1]+a[i]});
        /// order is important XXXXXXXxx
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
 
    cout<<solve(a,n);
   
}