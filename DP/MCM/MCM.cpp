#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];
int MCM(vector<int> a,int i,int j){
    if(i >= j){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k <= j-1; k++)
    {
       int tempAns = MCM(a,i,k) + MCM(a,k+1,j) + (a[i-1]*a[k]*a[j]);

        // ans = min(ans,tempAns);
        if(tempAns < ans)
        ans = tempAns;
    }
    
    return t[i][j] = ans;
}

int main(){
    memset(t,-1,sizeof(t));
    vector<int> a = {40,20,30,10,30};
    int i = 1,j = a.size()-1;
    cout<<MCM(a,i,j);
}