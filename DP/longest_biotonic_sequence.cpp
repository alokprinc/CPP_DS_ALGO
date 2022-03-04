#include<bits/stdc++.h>
using namespace std;
void sol(vector<int> arr,int n){
    int dp[n];
    dp[0] = 1;

    for(int i = 1 ; i < n; i++){
        int mx = INT_MIN;
        for(int j = 0; j < i ;j++){
            if(arr[i]>arr[j]){
                mx = max(mx,dp[j]);
            }
        }
        if(mx != INT_MIN) dp[i] = mx+1;
        else dp[i] = 1;
    }
    // for(int i = 0 ; i < n ; i++){
    //     cout<<dp[i]<<" ";
    // }cout<<endl;


    int dp2[n];
    dp2[n-1] = 1;

    for(int i = n-1 ; i >= 0; i--){
        int mx = INT_MIN;
        for(int j = n-1; j > i ;j--){
            if(arr[i] > arr[j]){
                mx = max(mx,dp2[j]);
            }
        }
        if(mx != INT_MIN) dp2[i] = mx+1;
        else dp2[i] = 1;
    }
    // for(int i = 0 ; i < n ; i++){
    //     cout<<dp2[i]<<" ";
    // }cout<<endl;
    int mx(-1);
    for(int i = 0 ; i < n; i++){
        mx = max(mx,dp[i]+dp2[i]-1);
    }
    cout<<mx<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }

    sol(arr,n);
}