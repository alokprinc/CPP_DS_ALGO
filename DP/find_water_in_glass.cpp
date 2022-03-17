#include<bits/stdc++.h>
using namespace std;

void sol(int k,int r,int c){
    double dp[k+1][k+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = k;
    for(int i = 0  ; i  < k+1;i++){
        for(int j = 0; j <= i; j++){
            if(dp[i][j] > 1.0){
                double spare = dp[i][j]-1.0;
               
                dp[i][j] = 1.0;
                dp[i+1][j] = spare/2.0;
                dp[i+1][j+1] = spare/2.0;
            }
            
        }
    }
    // for(int i = 0  ; i  < k+1;i++){
    //     for(int j = 0; j < k+1; j++){
    //        cout<<dp<<" "; 
    //     }cout<<endl;
    // }
    cout<<dp[r][c];
}
int main(){
    int k,r,c;
    cin>>k>>r>>c;
    sol(k,r,c);
}