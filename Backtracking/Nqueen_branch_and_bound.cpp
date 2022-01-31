#include<bits/stdc++.h>
using namespace std;

void nqueen(vector<vector<int>> chess,int r,vector<int> col,vector<int> d,vector<int> rd,int n,string asf){
    if(r == n){
        cout<<asf<<"."<<endl;

        return;
    }
    for(int c = 0; c < n; c++){
        if(col[c] == 0 and d[r+c]==0 and rd[r-c+ n - 1] == 0){
            col[c] = 1;
            d[r+c]=1;
            rd[r-c+ n - 1] = 1;
            nqueen(chess,r+1,col,d,rd,n,asf+to_string(r)+"-"+to_string(c)+", ");
            col[c] = 0;
            d[r+c]=0;
            rd[r-c+ n - 1] = 0;
        }
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> col(n,0);
    vector<int> d(2*n-1,0);
    vector<int> rd(2*n-1,0);
    vector<vector<int>> chess(n,vector<int>(n,0));
    nqueen(chess,0,col,d,rd,n,"");

}