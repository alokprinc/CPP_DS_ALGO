#include<bits/stdc++.h>
using namespace std;
void sol(string a,string b){
    int n = a.length();
    int m = b.length();
    int dp[n+1][m+1];
   
    for(int i = n; i >= 0; i--){
        for(int j = m; j >= 0; j--){
            if(i == n  and j == m){
                dp[i][j] = 0;
            }
            else if(i == n){
                dp[i][j] =(int)b[j]+dp[i][j+1];
            }else if(j == m){
                dp[i][j] =  (int)a[i]+dp[i+1][j];
            }else{
                if(a[i] != b[j])
                dp[i][j] = min((int)a[i]+dp[i+1][j],(int)b[j]+dp[i][j+1]);
                else
                dp[i][j] = dp[i+1][j+1];
            }
        }
    }
    // for(int i = 0; i < n+1; i++){
    //     for(int j = 0 ; j < m+1; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
    cout<<dp[0][0]<<endl;
}
int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    char ab = 'a';
   // cout<<(int)ab<<" "<<ab-0<<endl;
    sol(a,b);
}