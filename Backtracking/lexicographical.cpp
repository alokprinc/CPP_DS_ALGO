#include<bits/stdc++.h>
using namespace std;
void sol(int n,int i){
    
    if(i>n){
        return;
    }
    cout<<i<<endl;
    for(int j = 0 ;j < 10;j++){
        sol(n,10*i + j);
    }
}
int main(){
    int n;
    cin>>n;
   for(int i = 1; i < 10;i++){
       sol(n,i);
       
   }
}