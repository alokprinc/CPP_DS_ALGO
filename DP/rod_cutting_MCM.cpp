#include<bits/stdc++.h>
using namespace std;
void sol(vector<int> &arr,int n){
    int dp[n+1];
    dp[0]=0;
    dp[1] = arr[0];

    for(int i = 2 ; i < n+1 ; i++){
        int mn = INT_MIN;
        for(int j = 1; j <= i/2; j++){
            int cal = dp[j] + dp[i-j];
            mn = max(arr[i-1],max(mn,cal));
        }
        dp[i] = mn;
    }
    // for(int i = 0 ;i < n +1;i++){
    //     cout<<dp[i]<<" ";
    // }
    cout << dp[n] <<endl;
}
int main(){
    int n ;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    sol(arr,n);
}