#include<bits/stdc++.h>
using namespace std;
 #define vi vector<int>
 #define vvi vector<vi>
 #define pii pair<int, int>
 #define vpii vector<pii>
 #define lpf(i, a, b) for (int i = a; i < b; i++)
 #define lpb(i, b, a) for (int i = b; i >= a; i--)
 #define ff first
 #define ss Second
 const int N = 10e6;

class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};
 void sol(vector<Edge> graph[],vector<int> &comp,vector<int> &vis,int src){
      vis[src] = 1;
      comp.push_back(src);

      for(Edge a: graph[src]){
          if(!vis[a.nbr]){
              sol(graph,comp,vis,a.nbr);
          }
      }
  }
int main() {
  int vtces;
  cin >> vtces;
  vector<Edge>graph[vtces];

  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    int v1 ;
    int v2 ;
    int wt ;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back( Edge(v1, v2, wt));
    graph[v2].push_back( Edge(v2, v1, wt));
  }
  vvi comps;
  vi vis(vtces,0);

  lpf(i,0,vtces){
      if(!vis[i]){
          vi comp;
        sol(graph,comp,vis,i);
        comps.push_back(comp);
      }
  }
if(comps.size()==1){
    cout<<"true";
}
else{
    cout<<"false";
}

 
}