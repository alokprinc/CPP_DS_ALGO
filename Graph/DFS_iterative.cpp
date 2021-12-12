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

class Pair{
    public:
      int v;
      string psf;

      Pair(int v,string psf){
          this->v = v;
          this->psf = psf;
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
  int src;
  cin >> src;
  //write your code here
    vector<int> vis(vtces,0);
    stack<Pair> st;
    st.push({src,to_string(src)});

    while (!st.empty())
    {
        Pair rem = st.top();
        st.pop();

        if(vis[rem.v]){
            continue;
        } vis[rem.v] = 1;

        cout<<rem.v<<"@"<<rem.psf<<endl;

        for(auto a: graph[rem.v]){
            if(!vis[a.nbr]){
                st.push({a.nbr,rem.psf+to_string(a.nbr)});
            }
        }
    }
    


  return 0;
}