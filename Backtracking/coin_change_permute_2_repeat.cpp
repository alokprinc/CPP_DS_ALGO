#include<bits/stdc++.h>
using namespace std;
void coin_change(vector<int> coins,int ts,int cs,vector<int> vis,string ans){
    if(cs > ts){
        return;
    }
    else if(cs == ts){
        cout<<ans<<"."<<endl;
    }
    for(int i = 0 ; i < coins.size();i++){
        // if(!vis[i]){
        //     vis[i]=1;
            coin_change(coins,ts,cs+coins[i],vis,ans+to_string(coins[i])+"-");
        //     vis[i]=0;
        // }
    }
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
    vector<int> vis(n,0);
  coin_change(coins,sum,0,vis,"");
}