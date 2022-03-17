#include<bits/stdc++.h>
using namespace std;
void sol(vector<int> primes,int n){
   vector<int> dp(n+1);
    dp[1] = 1;
    vector<int> pointers(primes.size(),1);
    for(int i = 2 ; i < n +1 ;){    
        int mn = INT_MAX;
        int idx=0;
        for(int j = 0 ; j < primes.size();j++){
            if(mn > primes[j]*dp[pointers[j]]){
                mn = primes[j]*dp[pointers[j]];
                idx = j;
            }
        }
        if(dp[i-1] != mn){
             dp[i] = mn;
             i++;
        }
       
        pointers[idx]++;
    }
    // for(int i = 1 ; i < n+1; i++ ){
    //     cout<<dp[i]<<" ";
    // }
    cout<<dp[n];
}
int main(){

    int k; cin>>k;
    vector<int>  primes(k);
    for(int i = 0 ; i < k ; i++){
        cin>>primes[i];
    }

    int n;
    cin>>n;
    sol(primes,n);
}