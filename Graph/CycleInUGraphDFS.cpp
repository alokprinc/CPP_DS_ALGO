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
 const int N=10e5+7;
 vi adjl[N];
 
bool detectCycle(int node,int prev,vi vis,vi adjl[]){
    vis[node] = 1;
    for(auto it : adjl[node]){
        if(vis[it]==0){
            if(detectCycle(it,node,vis,adjl)) return true;
        } else if(it!=prev) return true;
    }
    return false;
}

bool checkCycleDfs(vi adjl[],int n){
    vi vis(n+1,0);
    lpf(i,1,n+1){
        if(!vis[i]){
            if(detectCycle(i,-1,vis,adjl)) return true;
        }
    }
    return false;
}

int main()
{
 
 int n,e;
 cin>>n>>e;
vi adjl[n];
 lpf(i,0,e){
     int x,y;
     cin>>x>>y;

     adjl[x].push_back(y);
     adjl[y].push_back(x);
 }
 
 cout<<checkCycleDfs(adjl,n);
}