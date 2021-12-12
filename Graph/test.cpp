#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

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

  int src;
  cin >> src;
  string psf;
  vector<int> bfs;
  vector<int> vis(vtces,0);
  while(bfs.size() != vtces)
   {
      if(!vis[src])
       {
            queue<int> q;
            q.push(src);
            vis[src] = 1;
            
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                
                for(auto it: graph[node])
                {
                    if(!vis[it.nbr])
                    {
                        q.push(it.nbr);
                        vis[it.nbr] = 1;
                    }
                }
            }
        }
    }
    
    for(auto a: bfs){
        cout<<a;
    }

  return 0;
}