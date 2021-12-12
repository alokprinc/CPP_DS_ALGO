#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vpii vector<pii>
#define lpf(i, a, b) for (int i = a; i < b; i++)
#define lpb(i, b, a) for (int i = b; i >= a; i--)
#define el cout << endl;
#define ff first
#define ss Second

class Edge
{
public:
  int src = 0;
  int nbr = 0;

  Edge(int src, int nbr)
  {
    this->src = src;
    this->nbr = nbr;
  }
};
class Pair{
  public:
   int v;
   int time;
   Pair(int v,int time){
       this->v = v;
       this->time = time;
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

    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));

  }
  int src, t;
  cin >> src;
  cin >> t;
    vector<int> vis(vtces,0);
  queue<Pair> q;
  q.push({src,1});
  int count(0);
  while(!q.empty()){
    Pair rem = q.front();
    q.pop();
    
    if(vis[rem.v]>0){
       
       continue; 
    }
    vis[rem.v] = rem.time;
     if(rem.time>t){
            break;
    }
    count++;
    
    for(auto a: graph[rem.v]){
        if(!vis[a.nbr]){
            q.push({a.nbr,rem.time+1});
        }
    }
  }

cout<<count;
  return 0;
}

