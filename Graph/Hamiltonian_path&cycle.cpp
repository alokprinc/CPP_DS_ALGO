#include <bits/stdc++.h>

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
void sol(vector<vector<Edge>> graph, unordered_set<int> &vis, int src, string psf, int osrc)
{
  if (vis.size() == graph.size() - 1)
  {
    bool Hcycle(false);
    for (auto it : graph[src])
    {

      if (it.nbr == osrc)
      {
        Hcycle = true;
      }
    }
    if (Hcycle)
    {
      cout << psf << "*" << endl;
    }
    else
    {
      cout << psf << "." << endl;
    }
  }
  vis.insert(src);

  for (Edge it : graph[src])
  {
    if (vis.find(it.nbr) == vis.end())
    {
      sol(graph, vis, it.nbr, psf + to_string(it.nbr), osrc);
    }
  }
  vis.erase(src);
}
int main()
{
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());

  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));
  }
  int src;
  cin >> src;

  unordered_set<int> vis;
  string psf = to_string(src);

  sol(graph, vis, src, psf, src);

  return 0;
}