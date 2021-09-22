#include<bits/stdc++.h>
using namespace std;

string print_LCSeq(string x,string y ,int n,int m){
    vector<vector<int>> t(n+1,vector<int>(m+1));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
        if(i == 0 || j == 0)
        t[i][j] = 0;
        }
        
    }
    
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }else{
                t[i][j] = max(t[i][j-1],t[i-1][j]);
            }
        }   
    }
    string ans;
   
    
    int i = n+1, j = m + 1;
    while( i > 0 , j > 0){
        if(x[i-1] == y[j-1]){
            ans.push_back(x[i-1]);
           
            j--;
            i--;
        }
        else{
            if(t[i][j-1] > t[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    ans.pop_back();
    return ans;
}

int main(){
    
    string x = "sunday";
    int n = x.size();
    string y = "saturday";
    int m = y.size();
   
      cout<< print_LCSeq(x,y, n, m);
   
}