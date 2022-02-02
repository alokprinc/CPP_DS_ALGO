#include<bits/stdc++.h>
using namespace std;
void coin_change(vector<int> coins,int ts,int cs,int i,string ans){
    if(i == coins.size()){
        if(cs == ts){
        cout<<ans<<"."<<endl;
        }
        return;
    }
    coin_change(coins,ts,cs+coins[i],i+1,ans+to_string(coins[i])+"-");
    coin_change(coins,ts,cs,i+1,ans);
}
int main(){
  int n;
  cin>>n;
    vector<int> coins(n);
  for(int i = 0 ; i < n ; i++){
      cin>>coins[i];
  }  
  int sum; cin>>sum;

  sort(coins.begin(),coins.end());

  coin_change(coins,sum,0,0,"");
}