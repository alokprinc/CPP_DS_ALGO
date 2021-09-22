#include<bits/stdc++.h>
using namespace std;

int min_num_coins(vector<int> a,int w){
    int n = a.size();
    vector<vector<int>> t(n+1,vector<int>(w+1));
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if(i == 0)
            t[i][j] = INT_MAX-1;

            if(j == 0)
            t[i][j] = 0;

            if(i == 0 && j  == 0)
            t[i][j] = 0;

            if(i == 1){
                if( j % a[i] != 0){
                    t[i][j] = INT_MAX-1;
                }
                else{
                    t[i][j] = j/a[i];
                }
            }
        }
    }

    for (int i = 2; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
            if(a[i-1] <= j){
                t[i][j] = min(1+t[i][j-a[i-1]],t[i-1][j]);
            }
            else if(a[i] > j){
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}

int main(){

    vector<int> coins = {2,3,5};
    int sum = 7;
    cout<< min_num_coins(coins,sum);
}