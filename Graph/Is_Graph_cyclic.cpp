#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vpii vector<pii>
#define lpf(i, a, b) for (int i = a; i < b; i++)
#define lpb(i, b, a) for (int i = b; i >= a; i--)
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

bool IsCyclic(vector<vector<Edge>> graph, vi vis, int src)
{
    // r m* w a*
    queue<pair<int, string>> q;
    q.push({src, to_string(src)});

    while (q.size() > 0)
    {
        // r
        pair<int, string> rem = q.front();
        q.pop();
        // m*
        if (vis[rem.first])
        {
            return true;
        }
        vis[rem.first] = 1;
        //w print if need 

        // a*
        for (auto it : graph[rem.first])
        {
            if(!vis[it.nbr]){
                q.push({it.nbr,rem.second+to_string(it.nbr)});
            }
        }
    }
    return false;
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

        graph[u].push_back(Edge(u, v));
        graph[v].push_back(Edge(v, u));
    }
    vi vis(vtces, 0);
    lpf(i, 0, vtces)
    {
        if (!vis[i])
        {
            bool cycle = IsCyclic(graph, vis, i);
            if (cycle)
            {
                cout << "true";
                return 0;
            }
        }
    }

    cout << "false";
}