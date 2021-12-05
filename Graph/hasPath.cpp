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

bool hasPath(vpii adjl[], int src, int des, vi vis)
{
    if (src == des)
    {
        return true;
    }

    vis[src] = 1;
    vector<pair<int, int>>::iterator it;
    for (it = adjl[src].begin(); it != adjl[src].end(); it++)
    {
        if (!vis[it->first])
        {
            bool hasNbrPath = hasPath(adjl, it->first, des, vis);
            if (hasNbrPath)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    int n, v;
    cin >> n >> v;
    vector<pair<int, int>> adjl[n];
    for (int i = 0; i < v; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;

        adjl[x].push_back({y, wt});
        adjl[y].push_back({x, wt});
    }

    int s, des;
    cin >> s >> des;
    vi vis(n, 0);
    cout << hasPath(adjl, s, des, vis);
    //  for (int i = 0; i < n; i++) 
    //     {
    //         cout << i << "->";
    //         vector<pair<int,int>> :: iterator it;
    //         for ( it = adjl[i].begin(); it != adjl[i].end();it++)
    //         {
    //             cout << it->first<<" "<<it->second<<" ";
    //         }

    //         cout << endl;

    //     }
}
