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

void topologicalSort(vector<vector<Edge>> graph,vector<int> &vis,int src,stack<int> &st){

    vis[src] = 1;

    for(auto a: graph[src]){
        if(!vis[a.nbr]){
            topologicalSort(graph,vis,a.nbr,st);
        }
    }
    st.push(src);
}

int main() {

  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());


  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v;
    cin >> u >> v;

    graph[u].push_back(Edge(u, v));
  }

 vector<int> vis(vtces,0);
  stack<int> st;

  for(int i = 0; i < vtces; i++){
      if(!vis[i]){
          topologicalSort(graph,vis,i,st);
      }
  }

    while (!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    
  return 0;
}