#include<bits/stdc++.h>
using namespace std;

pair<int,int> min_insert_delete(string a,string b,int n,int m){
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
           if(a[i-1] == b[j-1]){
               t[i][j] = 1 + t[i-1][j-1];
               
           }
           else{
             t[i][j] = max(t[i][j-1],t[i-1][j]);
           }
        }
    }
    
    int lcs = t[n][m];
    cout<<lcs<<endl;
    int del = n - lcs;
    int ins = m - lcs;
    pair<int,int> ans;
    ans.first = del;
    ans.second = ins;
    return ans;
}

int main(){
    string a = "heap";
    string b = "pea";
    int n = a.size();
    int m = b.size();

    cout<<"Number of deletion -> "<<min_insert_delete(a,b,n,m).first<<endl;
    cout<<"Number of insertion -> "<<min_insert_delete(a,b,n,m).second<<endl;
}