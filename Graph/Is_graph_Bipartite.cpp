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
    int val;
    int level;
    string psf;
    Pair(int val,int level,string psf){
        this->val = val;
        this->level = level;
        this->psf = psf;
    }
};

bool checkBiPartite(vector<vector<Edge>> graph,vi vis , int src,int level){
    queue<Pair> q;
    q.push({src,level,to_string(src)});
    while (!q.empty())
    {
        Pair rem = q.front();
        q.pop();

        if(vis[rem.val] != -1){
            if(rem.level != vis[rem.val]){
                return false;
            }
        }else{
            vis[rem.val] = rem.level;
        }

        for(auto it: graph[rem.val]){
            if(vis[it.nbr]==-1){
                q.push({it.nbr,rem.level+1,rem.psf+to_string(it.nbr)});
            }
        }

    }
    return true;
}

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

  vi vis(vtces,-1);
  int level = 0;
  lpf(i,0,vtces){
      if(vis[i]==-1){
          bool isBiPartite = checkBiPartite(graph,vis,i,level);
          if(!isBiPartite){
              cout<<"false";
              return 0;
          }
      
      }
  }
  
  cout<<"true"; 
  return 0;
}


