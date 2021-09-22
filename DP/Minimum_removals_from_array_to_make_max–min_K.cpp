#include<bits/stdc++.h>
using namespace std;
int dp[10001][10001];
// n2
int solve(int a[],int i,int j,int k){
    if(i >= j){
        return 0;
    }
    else if(a[j]-a[i] <= k){
        return 0;
    }
    else if(dp[i][j] != -1){
        return dp[i][j];
    }
    
        dp[i][j] = 1 + min(solve(a,i+1,j,k),solve(a,i,j-1,k));
    
    return dp[i][j];
}
// nlogn
int solve2(int a[],int k,int n){
    if(n==1){
        return 0;
    }
    else
    {
        int ans = n;
        for(int i =0; i< n ;i++){
            int j = upper_bound(a+i,a+n,a[i]+k) -a-1;
            ans = min(ans,n-(j-i+1));
        }
         return ans;
    }
   
}
int main(){
    int  a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20} ;
    int  k = 4;
    int n = 9;
    memset(dp,-1,sizeof(dp));
    if(n==0) cout<<0;
    else
    cout<<solve(a,0,n-1,k)<<endl;
    cout<<solve2(a,k,n);
}