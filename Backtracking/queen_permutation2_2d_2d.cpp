#include<bits/stdc++.h>
using namespace std;
void queen(vector<int> qn,int qsf,int n,int r,int c,string asf){
   if(r == n){
       
       if(qsf == n){
           cout<<asf<<endl;
           cout<<endl;
       }
       return;
   }
   int nr(0),nc(0);
   string sep="";
    if(c == n-1){
        nr= r+1;
        nc=0;
        sep = "\n";
    }else{
        nr=r;
        nc=c+1;
        sep = "\t";
    }
   for(int i = 0; i < n;i++){
       if(qn[i] == 0){
           qn[i] = 1;
           queen(qn,qsf+1,n,nr,nc,asf+"q"+to_string(i+1)+sep);
           qn[i] = 0;
       }
   }
}
int main(){
    int n;
    cin>>n;
   vector<int> qn(n,0);

    queen(qn,0,n,0,0,"");
}