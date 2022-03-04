#include<bits/stdc++.h>
using namespace std;

void solution(vector<int>&arr){
    int xorr = 0;
    for(auto a:arr){
        xorr ^= a;
    } 
    
    int rmsb = (xorr & -xorr);
    int onxor = 0;
    int offxor = 0;
    for(auto a:arr){
        if((a & rmsb) == 0){
            offxor ^= a;
        }else{
            onxor ^= a;
        }
    }
    if(onxor < offxor){
        cout<<onxor<<endl<<offxor;
    }else{
        cout<<offxor<<endl<<onxor;
    }
}
int main(){
    int n;
    cin>>n;
    
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    solution(arr);
}