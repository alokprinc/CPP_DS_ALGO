#include<bits/stdc++.h>
using namespace std;
void sol(vector<pair<int,int>> arr,int n){
    int dp[n];
    dp[0] = 1;
    for(int i = 1; i < n ; i++){
        int mx = INT_MIN;
        for(int j = 0 ; j < i; j++){
            if((arr[i].first >= arr[j].first) and (arr[i].second >= arr[j].second)){
                mx = max(mx,dp[j]);
            }
        }
        if(mx != INT_MIN)
            dp[i] = mx+1;
        else
            dp[i] = 1;
    }
    // for(int  i = 0 ; i < n ; i++){
    //     cout<<dp[i] <<" ";
    // }cout<<endl;
    int mx(-1);
    for(int i = 0 ; i < n ;i++){
        mx = max(mx,dp[i]);
    }
    cout<<mx<<endl;
}
struct comp{
    bool operator()(
        pair<int,int> a,
        pair<int,int> b
    ){
        return a.first > b.first;
    } 
};
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    for(int i = 0 ; i < n ; i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end());
    sol(arr,n);
}