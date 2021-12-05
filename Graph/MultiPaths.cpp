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
int spathw(INT_MAX), lpathw(INT_MIN), fpathw(INT_MIN), cpathw(INT_MAX);
string spath, lpath, fpath, cpath;

struct myComp
{
    bool operator()(
        pair<string, int> &a,
        pair<string, int> &b)
    {
        return a.second > b.second;
    }
};
priority_queue<pair<string, int>,vector<pair<string,int>>,myComp> pq;
//priority_queue<pair<string, int>,vector<pair<string,int>>,greater<pair<string,int>>> pq;
void hasPath(vpii adjl[], int src, int des, vi vis, string psf, int wsf, int val, int k)
{
    if (src == des)
    {
        if (wsf < spathw)
        {
            spathw = wsf;
            spath = psf;
        }

        if (wsf > lpathw)
        {
            lpathw = wsf;
            lpath = psf;
        }

        if (wsf > val and wsf < cpathw)
        {
            cpathw = wsf;
            cpath = psf;
        }

        if (wsf < val and wsf > fpathw)
        {
            fpathw = wsf;
            fpath = psf;
        }

        if (pq.size() < k)
        {
            pq.push({psf, wsf});
        }
        else
        {
            if (pq.top().second < wsf)
            {
                pq.pop();
                pq.push({psf, wsf});
            }
        }
    }

    vis[src] = 1;
    vector<pair<int, int>>::iterator it;
    for (it = adjl[src].begin(); it != adjl[src].end(); it++)
    {
        if (!vis[it->first])
        {
            hasPath(adjl, it->first, des, vis, psf + to_string(it->first), wsf + it->second, val, k);
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

    int src, des, val, k;
    cin >> src >> des >> val >> k;
    vi vis(n, 0);
    string psf;
    psf = to_string(src);
    int wsf = 0;
    hasPath(adjl, src, des, vis, psf, wsf, val, k);
    cout <<"Smallest Path = " << spath << "@" << spathw << endl;
    cout << "Largest Path = " <<lpath << "@" << lpathw << endl;

    cout <<  "Just Larger Path than "<<val<<" = " <<cpath << "@" << cpathw << endl;
    cout << "Just Smaller Path than "<<val<<" = " <<fpath << "@" << fpathw << endl;
    cout <<k<<"th largest path = "<<pq.top().first <<"@"<<pq.top().second;
    // cout<<endl;
    // for(int i = 0; i < pq.size();i++){
    //     cout<<pq.top().second<<endl;
    // }
}
