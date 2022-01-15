#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt)
  {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};
void hasPath(vector<Edge> graph[], int src, int des,string psf, vector<int> vis)
{
  if (src == des)
  { 
    cout<<psf<<endl;
    return;
  }
  vis[src] = 1;

  for (auto a : graph[src])
  {
    if (!vis[a.nbr])
    {
       hasPath(graph, a.nbr, des,psf+to_string(a.nbr), vis);
    }
  }
}
int main()
{
  int v, e;
  cin >> v >> e;
  vector<Edge> graph[v];
  for (int i = 0; i < e; i++)
  {
    int x, y, wt;
    cin >> x >> y >> wt;
    graph[x].push_back({x,y,wt});
     graph[y].push_back({y,x,wt});
  }
  int src, des;
  cin >> src >> des;
  vector<int> vis(v, 0);
  string psf;
  psf = to_string(src);
  hasPath(graph, src, des,psf, vis);
  
  return 0;
}