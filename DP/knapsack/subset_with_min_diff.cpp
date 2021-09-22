#include<bits/stdc++.h>
using namespace std;
bool subset_sum(vector<int> a,int w){
   int n = a.size();
    vector<vector<int>> t(n+1,vector<int>(w+1));
    
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if(i == 0)
            t[i][j] = false;

            if(j == 0)
            t[i][j] = true;
        }
        
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if(a[i-1] <= j){
                t[i][j] = t[i-1][j - a[i-1]] ||  t[i-1][j];
            }
            if(a[i-1] > j){
                t[i][j] = t[i-1][j];
            }
        }
        
    }
    return t[n][w];
}
int Subsets_with_min_diff(vector<int> a){
    int n = a.size();
    int range = 0;
    for(int i = 0 ; i < n ; i++){
        range += a[i];
    }
    int min = 0;
    for (int i = range/2; i >= 0; i--)
    {
        if(subset_sum(a,i) == true){
            min = i;
            break;
        }
    }
    
    return (range - 2*min);   
}

int main(){
    //vector<int> a = {1,0,1,0,1,0,1,1,1,0,0,1};
    vector<int> a = {14,10,6};
    cout<<Subsets_with_min_diff(a);
}