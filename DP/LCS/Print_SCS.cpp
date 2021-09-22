#include<bits/stdc++.h>
using namespace std;

string print_SCS(string x,string y,int n,int m){
    int t[n+1][m+1];
    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0 ; j < m+1; j++){
            if(i == 0 || j == 0)
            t[i][j] = 0;
        }
    }

    for(int i = 1; i < n +1 ; i++){
        for(int j = 1 ; j < m + 1 ; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1],t[i-1][j]);
            }
        }
    }

    int i = n+1, j = m+1;
    string ans;
    
    while(i > 0 , j > 0){
        if(x[i - 1] == y[j-1]){
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1] > t[i-1][j]){
                ans.push_back(y[j-1]);
                j--;
            }
            else{
                ans.push_back(x[i-1]);
                i--;
            }
        }
    }
    while(i > 0){
         ans.push_back(x[i-1]);
        i--;
    }
    while(j > 0){
         ans.push_back(y[j-1]);
        j--;
    }
    reverse(ans.begin(),ans.end());
    ans.pop_back();
    return ans;
}
int main(){
    string x = "abcd";
    string y = "efga";
    int n = x.size();
    int m = y.size();
    cout<<"SCS ->  "<<print_SCS(x,y,n,m)<<endl;
}