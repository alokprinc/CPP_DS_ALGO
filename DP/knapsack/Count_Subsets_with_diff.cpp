#include<bits/stdc++.h>
using namespace std;

int subset_count(vector<int> a,int w){
    int n = a.size();
    vector<vector<int>> t(n+1,vector<int>(w+1));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if(i == 0){
                t[i][j] = 0;
            }

            if((j == 0)){
                t[i][j] = 1;
            }
        }
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
            if(a[i-1] <= j){
                t[i][j] = t[i-1][j-a[i-1]] + t[i-1][j];
            }
            if(a[i-1] > j){
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}

int Count_subsets_with_diff(vector<int> a,int diff){
    int n = a.size();
    int range  = 0;
    for (int i = 0; i < n; i++)
    {
        range += a[i]; 
    }
    
    int sum = (range-diff)/2;

    int count = subset_count(a,sum);
    return count;
}

int main(){


    vector<int> a = {10, 9, 4, 5, 4, 8, 6};
    int diff = 1;
    cout<<Count_subsets_with_diff(a,diff);
}