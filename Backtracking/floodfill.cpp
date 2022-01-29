#include<bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<int>> maze, int i, int j, string asf,vector<vector<int>> &vis) {
    if(i < 0 or  j < 0 or i == maze.size() or j == maze[0].size() or maze[i][j] == 1 or vis[i][j]!=0){
        return;
    }if(i == maze.size()-1 and j == maze[0].size()-1){
        cout<<asf<<endl;
        return;
        
    }
    vis[i][j] = 1;
     floodfill(maze,i-1,j,asf+"t",vis);
    floodfill(maze,i,j-1,asf+"l",vis);
    floodfill(maze,i+1,j,asf+"d",vis);
     floodfill(maze,i,j+1,asf+"r",vis);
      vis[i][j] = 0;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector < vector < int >> arr(n, vector < int > (m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

vector<vector<int>> vis(n,vector<int>(m,0));
  floodfill(arr, 0, 0, "",vis);
  
}