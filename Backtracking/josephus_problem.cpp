#include<bits/stdc++.h>
using namespace std;
int sol(int n,int k){
    if(n==0){
        return 0;
    }
    int x = sol(n-1,k);
    int y = (x+k)%n;
    return y;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<sol(n,k);
}