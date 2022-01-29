#include<bits/stdc++.h>
using namespace std;

void combination(int cb,int tb,int ci,int ti,string psf){
    if(cb > tb){
        if(ci == ti){
            cout<<psf<<endl;
        }
        return;
    }
    combination(cb+1,tb,ci+1,ti,psf+"i");
    combination(cb+1,tb,ci,ti,psf+"-");
}
int main(){
    int box,item;
    cin>>box>>item;
    

    combination(1,box,0,item,"");

    return 0;
}