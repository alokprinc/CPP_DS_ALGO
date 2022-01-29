#include<bits/stdc++.h>
using namespace std;

void permute2(vector<int> item,int ti,int tb,int ci,string psf,int cb){
    if(cb>tb){
        
        if(ci == ti){
            
        cout<<psf<<endl;
        }
        return;
    }
    for(int i = 0; i < ti; i++){
        if(item[i]==0 ){
            item[i]=1;
            permute2(item,ti,tb,ci+1,psf+to_string(i+1),cb+1);
            item[i]=0;
            
        }
    }
    permute2(item,ti,tb,ci,psf+to_string(0),cb+1);
}

int main(){
    int box,item;
    cin>>box>>item;
    
    vector<int> itm(item,0);
    
    string psf="";
    permute2(itm,item,box,0,psf,1);
}