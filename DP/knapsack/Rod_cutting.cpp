#include<bits/stdc++.h>
using namespace std;
int max_price(vector<int> len,vector<int> val,int N){
    int n = len.size();
    int w = n;
    vector<vector<int>> t(n+1,vector<int>(w+1));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if(i == 0 || j == 0)
            t[i][j] == 0;
        }
        
    }

     for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if(len[i-1] <= j){
                t[i][j] = max(val[i-1] + t[i][j-len[i-1]],t[i-1][j]);
            }
            else if(len[i-1] > j){
                t[i][j] = t[i-1][j];
            }
        }
        
    }
    return t[n][w];
    
}
int main(){
    vector<int> len = {2,1,1};
    vector<int> price = {1,5,8,9,10,17,17,20};
    int N = 4;

    cout<<max_price(len,price,N); 
}