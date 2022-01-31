#include<bits/stdc++.h>
using namespace std;
void combination(int qsf,int tn,int n,vector<vector<int>> chess,int lval){
    if(qsf == n){
        
        for(auto a:chess){
            for(auto b:a){
                if(b==1){
                    cout<<"q\t";
                }else{
                    cout<<"-\t";
                }
            }cout<<endl;
        }
        cout<<endl;
        return;
    }
    
    for(int cell = lval+1;cell<tn;cell++){
       int  r = cell/n;
        int c = cell%n;
        
        chess[r][c] = 1;
        combination(qsf+1,tn,n,chess,cell);
        chess[r][c] = 0;
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> chess(n,vector<int>(n,0));
    combination(0,n*n,n,chess,-1);
}