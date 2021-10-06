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

void hasPath(vpii adjl[], int src, int des, vi vis,string psf)
{
    if (src == des)
    {
        cout<<psf<<endl;
        return ;
    }

    vis[src] = 1;
    vector<pair<int, int>>::iterator it;
    for (it = adjl[src].begin(); it != adjl[src].end(); it++)
    {
        if (!vis[it->first])
        {
            hasPath(adjl, it->first, des, vis,psf+to_string(it->first));
            
        }
    }
    vis[src] = 0;
  
}

int main()
{

    int n, v;
    cin >> n >> v;
    vpii adjl[n];
    for (int i = 0; i < v; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;

        adjl[x].push_back({y, wt});
        adjl[y].push_back({x, wt});
    }

    int src, des;
    cin >> src >> des;
    vi vis(n, 0);
    string psf;
    psf=to_string(src);
     hasPath(adjl, src, des, vis,psf);
    
}
