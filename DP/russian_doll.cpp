#include<bits/stdc++.h>
using namespace std;
void sol(vector<pair<int,int>> arr,int n){

    int dp[n];
    dp[0] = 1;

    for(int i = 1 ; i < n ; i++){
        int mx = INT_MIN;
        for(int j = 0 ;  j < i; j++){
            if(arr[i].first > arr[j].first and arr[i].second > arr[j].second){
                mx = max(mx,dp[j]);
            }
        }
        if(mx != INT_MIN)
            dp[i] = mx+1;
        else
            dp[i] = 1;
    }
    int mx(-1);
    for(int i = 0 ; i < n ;i++){
        mx = max(mx,dp[i]);
    }
    cout<<mx;
}
int main(){
    int n;
    cin>>n;

    vector<pair<int,int>> arr(n);
    for(int i = 0 ; i < n ;i++){
        int x,y;
        cin>>x>>y;
        arr[i] = {x,y};
    }
     sort(arr.begin(),arr.end());
    //  for(auto a: arr){
    //      cout<<a.first<<" "<<a.second<<endl;
    //  }
    sol(arr,n);
}