#include <bits/stdc++.h>
using namespace std;
unsigned long long int nCr(int n, int r){
    int mod = 1e9+7;
    unsigned long long int t[n+1][r+1];
      for(int i =0; i < n+1; i++){
          for(int j = 0 ; j < r+1; j++){
              if(i==0)
              t[i][j] = 0;
              
              if(j == 0)
              t[i][j] = 1;
              
              if(i == 0 & j == 0)
              t[i][j] = 0;
              
              if(i == j)
              t[i][j] = 1;
          }
      }
        // if(n == 0)
        // return 0;
        
        // if(r == 0 || r == n)
        // return 1;
      for(int i =1; i < n+1; i++){
          for(int j = 1 ; j < r+1; j++){
            
             t[i][j] = (t[i-1][j-1]+ t[i-1][j])%mod;
          }
      }
 
        // mp[temp] = nCr(n-1,r-1) + nCr(n-1,r);
        return t[n][r]%mod;
    }
int main(){
    cout<<nCr(716,128);
}