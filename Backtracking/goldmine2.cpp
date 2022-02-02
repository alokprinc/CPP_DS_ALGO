#include<bits/stdc++.h>
using namespace std;
void sol(vector<vector<int>> &mine,int i,int j,vector<vector<int>> &vis,vector<int> &sum){
    if(i < 0 or j < 0 or i >= mine.size() or j >= mine[0].size() or vis[i][j] == 1 or mine[i][j] == 0){
        return;
    }
    vis[i][j] = 1;
    sum.push_back(mine[i][j]);
    cout<<mine[i][j]<<endl;
    sol(mine,i,j+1,vis,sum);
    sol(mine,i+1,j,vis,sum);
    sol(mine,i,j-1,vis,sum);
    sol(mine,i-1,j,vis,sum);

}
int main(){
  int n,m;
  cin>>n>>m;

  vector<vector<int>> mine(n,vector<int>(m,0));
    for(int i = 0; i < n;i++){
        for(int j = 0 ; j < m; j++){
            cin>>mine[i][j];
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    int maxSum = INT_MIN;
    for(int i = 0; i < n;i++){
        for(int j = 0 ; j < m; j++){
            if(vis[i][j] == 0 and mine[i][j] != 0){
                vector<int> sum;
                sol(mine,0,0,vis,sum);
                for(auto a:sum){
                    maxSum = max(a,maxSum);
                }
            }
        }
    }
 cout<<maxSum<<endl;
    return 0;
}