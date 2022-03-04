#include<bits/stdc++.h>
using namespace std;
class Pair{
    public:
    int x;
    int y;
    string psf;
};
int sol(vector<vector<int>> &arr,int n,int m){
    
    int dp[n][m];

    
    for(int i = n-1; i >= 0 ; i--){
        for(int j = m-1; j >= 0; j--){
            if(j == m-1 and i == n-1){
                dp[i][j] = arr[i][j];
            }else if(i == n-1){
                dp[i][j] = arr[i][j]+dp[i][j+1];    
            }else if(j == m-1){
                dp[i][j] = arr[i][j]+dp[i+1][j];
            }else{
            dp[i][j] = arr[i][j]+min(dp[i][j+1],dp[i+1][j]);
            }
        }
    }

    // for(int i = n-1; i >= 0 ; i--){
    //     for(int j = m-1; j >= 0; j--){
    //         cout<<dp[i][j]<<" ";
    //     } cout<<endl;
    // }
    
   cout<<dp[0][0]<<endl;

    queue<Pair> q;
    q.push({0,0,""});
    while(!q.empty()){
        Pair rem = q.front();
        q.pop();

       if(rem.x == n-1 and rem.y == m-1){
           cout<<rem.psf<<endl;
       }else if(rem.x == n-1){
           q.push({rem.x,rem.y+1,rem.psf+"H"});
       }else if(rem.y == m-1){
           q.push({rem.x+1,rem.y,rem.psf+"V"});
       }else{
           if(dp[rem.x][rem.y+1] < dp[rem.x+1][rem.y]){
               q.push({rem.x,rem.y+1,rem.psf+"H"});
           }else if(dp[rem.x][rem.y+1] > dp[rem.x+1][rem.y]){
                q.push({rem.x+1,rem.y,rem.psf+"V"});
           }else{
               q.push({rem.x+1,rem.y,rem.psf+"V"});
               q.push({rem.x,rem.y+1,rem.psf+"H"});    
           }
       }
    }
    return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin>>arr[i][j];
        }
    }

    // for(auto a: arr){
    //     for(auto b:a){
    //         cout<<b<<" ";
    //     }cout<<endl;
    // }

   sol(arr,n,m);
}