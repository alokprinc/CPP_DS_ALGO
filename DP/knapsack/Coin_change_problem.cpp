#include<bits/stdc++.h>
using namespace std;
int Num_ways(vector<int> a,int w){
    int n = a.size();
    vector<vector<int>> t(n+1,vector<int>(w+1));
    
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if(i == 0 )
            t[i][j] = 0;
            
            if(j == 0)
            t[i][j] = 1;
        }
    }
    
     for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
            if(a[i-1] <= j){
                t[i][j] = t[i][j - a[i-1]] + t[i-1][j];
            }
            else if(a[i-1] > j){
                 t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}
long long int count(long long int w)
{
    int wt[]= {3,5,10};
    int n = 3;
	long long int dp[n+1][w+1];
	
	for(int i = 0; i < n +1 ; i++){
	    for(int j = 0 ; j < w+1; j++){
	        if(i == 0 )
	        dp[i][j] = 0;
	        
	        if(j == 0)
	        dp[i][j] = 1;
	    }
	}
	for(int i = 1; i < n +1 ; i++){
	    for(int j = 1 ; j < w+1; j++){
	        if(wt[i - 1] <= j){
	            dp[i][j] = dp[i][j - wt[i-1]] + dp[i-1][j];
	        }
	        else if(wt[i-1]>j){
	            dp[i][j] = dp[i - 1][j];
	        }
	    }
	}
    
	return dp[n][w];
}
int main(){

    vector<int> coin = {3,5,10};
    int sum = 20;
    
    cout<<Num_ways(coin,sum)<<" "<<count(sum);
}