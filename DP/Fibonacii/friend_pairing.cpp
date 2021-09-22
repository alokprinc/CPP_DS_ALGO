#include <bits/stdc++.h>
using namespace std;
int countFriendsPairings(int n) 
    { 
        vector<long long int> t(n+1);
       int mod = 1e9+7;
        
        for(int i = 0; i < n+1; i++){
            if(i<=2)
            t[i] = i;
            
            if(i > 2){
                t[i] =( t[i-1] + (i-1)*t[i-2])%mod;
            }
        }
        return t[n]%mod;
    }

    int main(){
    cout<<countFriendsPairings(6569);
}