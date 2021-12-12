#include<bits/stdc++.h>
using namespace std; 
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
#define lpf(i,a,b) for(int i = a; i < b;i++)
#define lpb(i,b,a) for(int i = b; i >= a;i--)
#define el cout<<endl;
#define ff first
#define ss Second
const int N = 10e5;

vi adjl[N]; 
 
bool detectCycle(int i ,vi vis,vi adjl[],int n){
    
    queue<pii> q;
    vis[i] = true;
    q.push({i,-1});

    while (!q.empty())
    {
        int node = q.front().first;
        int prev =  q.front().second;

        for(auto it : adjl[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it,node});
            }
            else if(prev != it){
                return true;
            }
        }
    }
    return false;
}

 bool checkCycle(vi adjl[],int n){
     vi vis(n+1,0);
     
     lpf(i,1,n+1){
         if(!vis[i]){
             if(detectCycle(i,vis,adjl,n)) return true;
             else return false;
         }
     }
 }
 
int main()
{
 
 int n,v;
 cin>>n>>v;

lpf(i,0,v){
    int x,y;
    cin>>x>>y;

    adjl[x].push_back(y);
    adjl[y].push_back(x);
}
 lpf(i,1,n+1){
     cout<<i<<"->";
     for(auto it : adjl[i]){
         cout<<it<<" ";
     } cout<<endl;
 }

cout<< checkCycle(adjl,n);
}