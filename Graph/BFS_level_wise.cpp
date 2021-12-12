#include <bits/stdc++.h>
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
    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));
  }

  int src;
  cin >> src;

  queue<pair<int, string>> q;
  q.push({src, to_string(src) + ""});
  vector<int> vis(vtces, 0);

  while (q.size() > 0)
  {
    // r m* w a*
    pair<int, string> rem = q.front();
    q.pop();

    if (vis[rem.first])
    {
      continue;
    }
    vis[rem.first] = 1;

    cout << rem.first << "@" << rem.second << endl;

    for (auto a : graph[rem.first])
    {
      if (!vis[a.nbr])
      {
        q.push({a.nbr, rem.second + to_string(a.nbr)});
      }
    }
  }

  return 0;
}