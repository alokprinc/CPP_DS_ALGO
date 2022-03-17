#include <bits/stdc++.h>
using namespace std;
class Pair{
    public:
    int idx;
    int step;
    int jump;
    string psf;
   
};
void sol(vector<int> &arr, int n)
{
    vector<int> dp(n);
     for(int i = 0; i < n; i++)
        dp[i] = INT_MAX;
 
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int mn = INT_MAX;

        if (arr[i] > 0)
        {
            for (int j = 1; j <= arr[i] and i+j < arr.size(); j++)
            {
                // if(dp[i+j] != INT_MAX and dp[i+j] < mn){
                //     mn = dp[i+j];
                // }
                mn = min(dp[i+j],mn);
            }
            if (mn != INT_MAX)
            {
                dp[i] = mn + 1;
            }
        }
    }
    cout<<dp[0]<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     if(dp[i] != INT_MAX){
    //     cout << dp[i] << " ";
    //     }else{
    //         cout<<"n"<<" ";
    //     }
    // }

    queue<Pair> q;
    int step = arr[0];
    int jump = dp[0];
    q.push({0,step,jump,"0"});

    while(!q.empty()){
        Pair rem = q.front();
        q.pop();
        if(rem.jump == 0){
            cout<<rem.psf<<" ."<<endl;
        }
        for(int i = 1; i <= rem.step and rem.idx +i  < n; i++){
         int x = rem.idx+i;
         if(dp[x] == rem.jump-1){
             q.push({x,arr[x],dp[x],rem.psf.length()==0?rem.psf+to_string(x):rem.psf+" -> "+to_string(x)});
         }   
        }
    }

}
int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sol(arr, n);
}