#include<bits/stdc++.h>
using namespace std;

int Count_subsets(vector<int> a,int sum){
    int n = a.size();
    int w = sum;

    vector<vector<int>> t(n+1,vector<int>(w+1));
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if(i == 0){
                t[i][j] = 0;
            }
            if(j == 0){
                t[i][j] = 1;
            }
        }
        
    }
     for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
           if(a[i-1] <= j){
               t[i][j] = t[i-1][j - a[i-1]] + t[i-1][j];
           }
           else if(a[i-1] > j){
               t[i][j] =   t[i-1][j];
           }
        }
        
    }
    return t[n][w];
     
}

int main(){

    vector<int> a = {2,3,5,8,10};
    int sum = 10;
    cout<<Count_subsets(a,sum);
}