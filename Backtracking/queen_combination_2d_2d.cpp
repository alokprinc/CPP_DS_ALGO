#include<bits/stdc++.h>
using namespace std;
void queen(int qsf,int n,int i,int j,string asf){
    if(i == n ){
        if(qsf == n){
        cout<<asf<<endl;
        }
        return;
    }
    int ni=0; int nj=0; string y,no;
    if(j == n-1){
        ni = i+1;
        nj=0;
        y = asf+"q\n";
        no =asf+ "-\n";
    }else{
        ni = i;
        nj = j+1;
        y = asf+"q";
        no = asf+"-";
    }
    queen(qsf+1,n,ni,nj,y);
    queen(qsf+0,n,ni,nj,no);
}
int main(){
    int n;
    cin>>n;
  //  vector<vector<int>> qn(n,vector<int>(n,0));

    queen(0,n,0,0,"");
}