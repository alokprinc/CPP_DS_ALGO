#include<bits/stdc++.h>
using namespace std;

int fun(int arr[],int n){
    
    vector<int> dp(n,1e6);
    dp[0] = 0;

    for(int i = 1; i < n ; i++){
        for(int j = 0; j < i ; j++){
            if( i <= (j + arr[j])){
                dp[i] = min(dp[i],1+dp[j]);
            }
        }
    }
    return dp[n-1];
}
int main(){
    int arr[] = {10 ,2 ,3 ,1 ,1 ,2 ,4 ,2 ,0, 1, 1};
    int n = 11;
    cout<<fun(arr,n);
}