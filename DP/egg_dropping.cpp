#include<bits/stdc++.h>
using namespace std;
void sol(int e,int f){
    int dp[e+1][f+1];

    for(int i = 0 ; i < e+1; i++){
        for(int j = 0 ; j < f+1; j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            else if(j == 0){
                dp[i][j] = 0;
            }
            else if(j == 1){
                dp[i][j] = 1;
            }else if(i == 1){
                dp[i][j] == j;
            }else{
                int mn = INT_MAX;
                for(int pj = 0,cj = j-1;cj >= 0; pj++,cj--){
                    int pval = dp[i-1][pj];
                    int cval = dp[i][cj];
                    int mx = max(pval,cval);
                    mn = min(mx,mn);
                }
                dp[i][j] = mn+1;
            }
        }
    }
    cout<<dp[e][f];
}
int main(){
    int e,f;
    cin>>e>>f;

    sol(e,f);
}