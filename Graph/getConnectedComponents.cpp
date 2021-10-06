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

void Graph(vpii graph[], int src, vi comp, vi vis)
{
    vis[src] = 1;
    comp.push_back(src);
    vpii ::iterator it;
    for (it = graph[src].begin(); it != graph[src].end(); it++)
    {
        if (!vis[it->ff])
        {
            Graph(graph, it->first, comp, vis);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vpii graph[v];
    lpf(i, 0, e)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
        graph[y].push_back({x, wt});
    }
    int src;
    cin >> src;
    vi vis(v, 0);
    vvi comps;

    lpf(i, 0, v)
    {
        if (!vis[i])
        {
            vi comp;
            Graph(graph, src, comp, vis);
            comps.push_back(comp);
        }
    }
   
    for(int f:comps)
    {
        cout << "[";
        for (int itr: f)
        {

            cout << itr << "m ";
        }
        cout << endl;
    }
}