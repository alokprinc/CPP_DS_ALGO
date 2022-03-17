#include<bits/stdc++.h>
using namespace std;
void sol(string s1,string s2,int n,int m){
    int dp[n+1][m+1];
    int mx = INT_MIN;
    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0 ; j < m+1;j++){
            if( i == 0 || j == 0){
                dp[i][j] = 0;
            }else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                mx = max(mx,dp[i][j]);
            }else {
                dp[i][j] = 0;
            }
        }
    }
    cout<<mx<<endl;
}
int main(){
    string s1;
    getline(cin,s1);

    string s2;
    getline(cin,s2);

    sol(s1,s2,s1.length(),s2.length());
}