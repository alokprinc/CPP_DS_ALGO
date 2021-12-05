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
const int N = 10e6;

vi BFS(vi adjL[], int v)
{
    vi bfs;
    vi vis(v + 1, 0);

    lpf(i, 1, v + 1)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adjL[node])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}
void dfsp(vi &dfs, vi &vis, vi adjL[], int node)
{
    dfs.push_back(node);
    vis[node] = 1;

    for (auto it : adjL[node])
    {
        if (!vis[it])
        {
            dfsp(dfs, vis, adjL, it);
        }
    }
    
}
vi DFS(vi adjL[], int n)
{
    vi vis(n + 1, 0);
    vi dfs;
    lpf(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dfsp(dfs, vis, adjL, i);
        }
    }
    return dfs;
}
void printBFS(vi adjL[], int nodes)
{
    cout << "BFS of graph" << endl;
    vi bfs = BFS(adjL, nodes);
    for (auto a : bfs)
    {

        cout << a << " ";
    }
}
void printDFS(vi adjL[], int nodes)
{
    cout << "DFS of graph" << endl;
    vi dfs = DFS(adjL, nodes);
   
    for (auto a : dfs)
    {
        cout << a << " ";
    }
    
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vi adjL[nodes + 1];
    lpf(i, 1, edges + 1)
    {
        int x, y;
        cin >> x >> y;

        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    cout << "Adj list given below" << endl;
    lpf(i, 1, nodes + 1)
    {
        cout << i << " -> ";
        for (auto it : adjL[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }

   // printBFS(adjL, nodes);
    printDFS(adjL, nodes);
}