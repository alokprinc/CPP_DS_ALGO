#include<bits/stdc++.h>
using namespace std;
void queen(int qsf,int n,vector<vector<int>> qn){

    if(qsf >n){

        for(auto a:qn){
            for(auto b:a){
                if(b == 0){
                    cout<<"-"<<"\t";
                }else{
                    cout<<"q"<<b<<"\t";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0;j  < n ; j++){
            if(qn[i][j] == 0){
                qn[i][j] = qsf;
                queen(qsf+1,n,qn);
                qn[i][j] = 0;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> qn(n,vector<int>(n,0));

    queen(1,n,qn);
}