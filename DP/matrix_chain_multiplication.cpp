#include<bits/stdc++.h>
using namespace std;
void sol(vector<int> arr,int n){

    int dp[n-1][n-1];
    memset(dp,0,sizeof(dp));
    for(int g = 0 ; g < n-1;g++){
        for(int i = 0,j = g;i<n-1, j < n-1;i++,j++){
            if(g == 0){
                dp[i][j] = 0;
            }else if(g == 1){
                dp[i][j] = arr[i]*arr[j]*arr[j+1];
            }else {
                int mn = INT_MAX;
                for(int k = i; k < j ;k++){
                    int lc = dp[i][k];
                    int rc = dp[k+1][j];
                    int mc = arr[i]*arr[k+1]*arr[j+1];
                    mn  = min(mn,lc+rc+mc);
                }
                dp[i][j] = mn;
            }    
        }
    }
    for(int i = 0 ; i < n-1; i++){
        for(int j = 0 ; j < n-1; j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    cout<<dp[0][n-2];
}
int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sol(arr,n);
}