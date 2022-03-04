#include<bits/stdc++.h>
using namespace std;
void sol(vector<int> arr,int n){
    int dp[n];
    dp[0] = arr[0];
    for(int i = 1 ; i < n; i++){
        int mx = INT_MIN;
        for(int j = 0; j < i; j++){
            if(arr[i] >= arr[j] ){
                mx = max(mx,dp[j]);
            }
        }
        if(mx != INT_MIN){
            dp[i] = arr[i]+mx;
        }else{
            dp[i] = arr[i];
        }
    }
    //  for(int i = 0 ; i < n ;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    int mx(-1);

    for(int i = 0 ; i < n ; i++){
        //cout<<dp[i]<<" ";
        mx = max(mx,dp[i]);
    }
    cout<<endl<<mx<<endl;
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