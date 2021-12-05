#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vpii vector<pair<int,int>>

void printAllPath(vpii adjl[],vi vis,int src,int des,string psf){
    if(src == des){
        cout<<psf<<endl;
        return;
    }
    
    vis[src] = 1;
    
    vpii :: iterator it;
    for(it = adjl[src].begin();it != adjl[src].end(); it++){
        if(!vis[it->first]){
            printAllPath(adjl,vis,it->first,des,psf+to_string(it->first));
        }
    }
    vis[src] = 0;
}

int main(){
    int node,edge;
    cin>>node>>edge;
    vpii adjl[node];
    for(int i = 0; i < edge;i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        
        adjl[a].push_back({b,wt});
        adjl[b].push_back({a,wt});
    }
    
    int src,des;
    cin>>src>>des;
    vi vis(node,0);
    string psf;
    psf = to_string(src);
    printAllPath(adjl,vis,src,des,psf);
}