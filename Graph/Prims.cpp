#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;
  int wt = 0;

  Edge(int src, int nbr, int wt)
  {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};

class Pair{
  public:
    int v;
    int av;
    int wt;
    
    Pair(int v,int av,int wt){
        this->v = v;
        this->av = av;
        this->wt = wt;
    }
    
};

struct myComp
{
  bool operator()(
      Pair &a,
      Pair &b)
      {
          return a.wt > b.wt;
      }  
};

int main() {

  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));

  }

 vector<int> vis(vtces,0);
 
 priority_queue<Pair,vector<Pair>,myComp> pq;
 pq.push({0,-1,0});
 
 while(!pq.empty()){
     Pair rem = pq.top();
     pq.pop();
     
     if(vis[rem.v]){
         continue;
     } vis[rem.v] =1;
     
     if(rem.av != -1){
         cout<<"["<<rem.v<<"-"<<rem.av<<"@"<<rem.wt<<"]"<<endl;
     }
     
     for(auto a: graph[rem.v]){
         if(!vis[a.nbr]){
             pq.push({a.nbr,a.src,a.wt});
         }
     }
 }


  return 0;
}


























