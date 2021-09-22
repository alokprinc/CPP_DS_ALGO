#include<bits/stdc++.h>
using namespace std;
 int fun(string str){
     int n = str.length();
    int dp[n];
    dp[0] = 1;
    for(int i = 1; i <=n; i++){
        if(str.at(i-1)== '0' and str.at(i)== '0'){
            dp[i] = 0;
        }
       else if(str.at(i-1)!= '0' and str.at(i)== '0'){
            if(str.at(i-1)== '1'  || str.at(i-1)== '2')
            dp[i] = (i>=2 ? dp[i-2] : 1);
            else
            dp[i] = 0;
        }
        else if(str.at(i-1)== '0' and str.at(i)!= '0'){
            dp[i] = dp[i-1];
        }
        else{
             if(str.substr(i-1,i+1) -'0' <= 26))
             dp[i] = dp[i-1] + (i>=2 ? dp[i-2] : 1);
             else
             dp[i] = dp[i-1];
        }
    }
   return dp[n-1];
}
int main(){
    int str;
    cin>>str;
    cout<<fun(str);
}