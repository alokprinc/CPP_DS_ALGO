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
  int wt = 0;

  Edge(int src, int nbr,int wt)
  {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};
class Pair{
  public:
   int v;
   int wsf;
   string psf;
   Pair(int v,int wsf,string psf){
       this->v = v;
       this->wsf = wsf;
       this->psf = psf;
   }
   
   
};
struct myComp
{
    bool operator()(
        Pair &a,
        Pair &b)
    {
        return a.wsf > b.wsf;
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

    graph[u].push_back(Edge(u, v,w));
    graph[v].push_back(Edge(v, u,w));

  }
  int src;
  cin >> src;
  
    vi vis(vtces,0);
    int wsf(0);
    priority_queue<Pair,vector<Pair>,myComp> pq;
    pq.push({src,wsf,to_string(src)});

    while (pq.size()>0)
    {
        Pair rem = pq.top();
        pq.pop();

        if(vis[rem.v]==1){
            continue;
        }
         vis[rem.v] = 1;

        cout<<rem.v<<" via "<<rem.psf<<" @ "<<rem.wsf<<endl;

        for(auto a: graph[rem.v]){
            if(!vis[a.nbr]){
                pq.push({a.nbr,rem.wsf+a.wt,rem.psf+to_string(a.nbr)});
            }
        }
    }
    
    

  return 0;
}

