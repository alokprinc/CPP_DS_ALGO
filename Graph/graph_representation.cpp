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
cout<< "adjm is shown below"<<endl;
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

void adjList(){
    int n, m;
    cin >> n >> m;
    // non weighted
    vi adjL[n+1]; // n+1 for 1 based indexing
    // weighted graph
    vpii adjL[n+1];

    lpf(i,0,m){
        // non weighted graph
        int x,y;
        cin>>x>>y;

        adjL[x].push_back(y);
        adjL[y].push_back(x);

        // weighted graph

        //  int x,y,wt;
        // cin>>x>>y>>wt;

        // adjL[x].push_back({y,wt});
        // adjL[y].push_back({x,wt});

    }
    cout<< "adjL is shown below"<<endl;
    lpf(i,1,n+1){
       cout<<i<<"->";
       for(int x: adjL[i]){
           cout<<x<<" ";
       } cout<<endl;
    }
}
int main()
{ 
    // adjMartix();

    // adjList();
   
}