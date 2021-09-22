#include<bits/stdc++.h>
using namespace std;
// approch 2
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//   int n, m;
//   cin >> n >> m;
//   vector<vector<int>> a(n, vector<int>(m));

//   for (int i = 0; i < n ; i++) {
//     for (int j = 0; j < m; j++) {
//       cin >> a[i][j];
//     }
//   }

//   int dp[n][m];
//   int l = INT_MAX;
//   int sl = INT_MAX;
//   for (int i = 0; i < m; i++) {
//     dp[0][i] = a[0][i];
//     if (dp[0][i] <= l) {
//       sl = l;
//       l = dp[0][i];
//     }
//     else if (dp[0][i] <= sl) {
//       sl = dp[0][i];
//     }
//   }

//   for (int i = 1; i < n; i++) {
//     int nl = INT_MAX;
//     int nsl = INT_MAX;
//     for (int j = 0; j < m; j++) {
//       if ( l != dp[i-1][j]) {
//         dp[i][j] = l + a[i][j];
//       }
//       else {
//         dp[i][j] = sl + a[i][j];
//       }

//       if (dp[i][j] <= nl) {
//         nsl = nl;
//         nl = dp[i][j];
//       }
//       else if (dp[i][j] <= nsl) {
//         nsl = dp[i][j];
//       }
//     }
//     l = nl;
//     sl = nsl;
//   }
  
//   cout << l;

// }
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    
    for(int i = 0; i < n ; i++){
        for(int j = 0;j <m;j++){
            cin>>a[i][j];
        }
    }
    
    int dp[n][m];
    for(int i = 0; i < m;i++){
        dp[0][i] = a[0][i];  
    }
    
    for(int i = 1; i < n; i++){
       for(int j = 0; j < m; j++){
           int mn = INT_MAX;
           for(int k = 0; k < m; k++){
               if(k != j){
                   mn = min(mn,dp[i-1][k]);
               }
           }
           dp[i][j] = a[i][j] + mn;
       }
    }
    int ans = INT_MAX;
    for(int i = 0; i < m ; i++){
    ans  = min(ans,dp[n-1][i]);
    }
    cout<<ans;
    
}