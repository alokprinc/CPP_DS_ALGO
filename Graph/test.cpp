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

struct myComp
{
  bool operator()(
      pair<int, string> &a,
      pair<int, string> &b)
  {
    return a.first > b.first;
  }
};
string spath;
int spathwt = INT_MAX;
string lpath;
int lpathwt = INT_MIN;
string cpath;
int cpathwt = INT_MAX;
string fpath;
int fpathwt = INT_MIN;

priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;

void multisolver(vector<Edge> graph[], int src, int dest, vector<int> vis, int cap, int k, string psf, int wsf)
{
  if (src == dest)
  {
    if (spathwt > wsf)
    {
      spathwt = wsf;
      spath = psf;
    }
    if (lpathwt < wsf)
    {
      lpathwt = wsf;
      lpath = psf;
    }
    if (wsf > cap and cpathwt > wsf)
    {
      cpathwt = wsf;
      cpath = psf;
    }
    if (wsf < cap and fpathwt < wsf)
    {
      fpathwt = wsf;
      fpath = psf;
    }

    if (pq.size() < k)
    {
      pq.push({wsf, psf});
    }
    else
    {
      if (wsf > pq.top().first)
      {
        pq.pop();
        pq.push({wsf, psf});
      }
    }
  }
  vis[src] = 1;

  for (auto e : graph[src])
  {
    if (!vis[e.nbr])
    {
      multisolver(graph, e.nbr, dest, vis, cap, k, psf + to_string(e.nbr), wsf + e.nbr);
    }
  }
  vis[src] = 0;
}

int main()
{

  int vtces;
  cin >> vtces;
  vector<Edge> graph[vtces];

  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++)
  {
    int v1;
    int v2;
    int wt;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back(Edge(v1, v2, wt));
    graph[v2].push_back(Edge(v2, v1, wt));
  }

  int src;
  cin >> src;
  int dest;
  cin >> dest;

  int criteria;
  cin >> criteria;
  int k;
  cin >> k;

  vector<int> visited(vtces, 0);
  multisolver(graph, src, dest, visited, criteria, k, src + "0", 0);

  cout << "Smallest Path = " << spath << "@" << spathwt << endl;
  cout << "Largest Path = " << lpath << "@" << lpathwt << endl;
  cout << "Just Larger Path than " << criteria << " = " << cpath << "@" << cpathwt << endl;
  cout << "Just Smaller Path than " << criteria << " = " << fpath << "@" << fpathwt << endl;
  cout << k << "th largest path = " << pq.top().second << "@" << pq.top().first << endl;

  return 0;
}