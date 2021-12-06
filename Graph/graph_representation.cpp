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
// non weighted
vi adjL[N + 1]; // n+1 for 1 based indexing
// weighted graph
vpii adjLW[N + 1];
void adjMartix()
{
    int n, m;
    cin >> n >> m;

    vvi adjm(n + 1, vi(n + 1, 0));

    lpf(i, 0, m)
    {
        int x, y;
        cin >> x >> y;

        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }
    cout << "adjm is shown below" << endl;
    lpf(i, 1, n + 1)
    {
        lpf(j, 1, n + 1)
        {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }
    // checking edge exist bw two nodes
    if (adjm[3][7] == 1)
    {
        cout << "edge found" << endl;
    }
    else
    {
        cout << "no edge" << endl;
    }
}

vi adjList()
{
    // n number of nodes  m number of edges
    int n, m;
    cin >> n >> m;
    // non weighted

    lpf(i, 1, m)
    {
        // non weighted graph
        int x, y;
        cin >> x >> y;

        adjL[x].push_back(y);
        adjL[y].push_back(x);

        // weighted graph

        //  int x,y,wt;
        // cin>>x>>y>>wt;

        // adjLW[x].push_back({y,wt});
        // adjLW[y].push_back({x,wt});
    }
    cout << "adjL is shown below" << endl;
    lpf(i, 1, n + 1)
    {
        cout << i << "->";
        for (int x : adjL[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return adjL[n + 1];
}

vi BFS(vi adj[], int v)
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

                for (auto it : adj[node])
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

// DFS
void DFS(int node, vi &vis, vi adjl[], vi &dfs)
{
    dfs.push_back(node);
    vis[node] = 1;

    for (auto it : adjl[node])
    {
        if (!vis[it])
        {
            DFS(it, vis, adjl, dfs);
        }
    }
}
vi dfsOfGraph(vi adjl[], int v)
{
    vi dfs;
    vi vis(v + 1, 0);
    lpf(i, 1, v + 1)
    {
        if (!vis[i])
        {
            DFS(i, vis, adjl, dfs);
        }
    }
    return dfs;
}
int main()
{
    // adjMartix();

    adjList();

    //    // vi ans  = BFS(adjL,7);
    //     vi ans  = dfsOfGraph(adjL,7);

    //     lpf(i,0,7){
    //         cout<<ans[i]<<" ";
    //     }
}