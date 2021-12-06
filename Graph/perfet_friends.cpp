#include<bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
#define lpf(i,a,b) for(int i = a; i < b;i++)
#define lpb(i,b,a) for(int i = b; i >= a;i--)
#define el cout<<endl;
#define ff first
#define ss Second
const int N = 10e5;

void sol(vi adjl[],vi &vis,vi &comp,int src){
    vis[src] = 1;
    comp.push_back(src);
    
    for(auto it:adjl[src]){
        if(!vis[it]){
            sol(adjl,vis,comp,it);
        }
    }
}

int main() {
  int n;
  cin >> n;

  int k;
  cin >> k;

  vi adjl[n];
  
  lpf(i,0,k){
      int a,b;
      cin>>a>>b;
      
      adjl[a].push_back(b);
      adjl[b].push_back(a);
      
  }
    vi vis(n,0);
    vvi comps;
    
    lpf(i,0,n){
        if(!vis[i]){
            vi comp;
            sol(adjl,vis,comp,i);
            comps.push_back(comp);
        }
    }
    int pair(0);
    lpf(i,0,comps.size()){
        lpf(j,i+1,comps.size()){
            int count = comps[i].size()*comps[j].size();
            pair += count;
        }
    }
    cout<<pair;
  return 0;
}
