#include<bits/stdc++.h>
using namespace std;
vector<int> kadane(vector<int> arr,int n){
    int cs = arr[0];
    int os = arr[0];
    vector<int> osarr;
    osarr.push_back(arr[0]);
    for(int i = 1 ; i < n ;i++){
        if(cs >= 0){
            cs+=arr[i];
        }else{
            cs = arr[i];
        }
        os = max(os,cs);
        osarr.push_back(os);
    }
    return osarr;
}
int sol(vector<int> arr,int n,int k){
    vector<int> sumarr = kadane(arr,n);
    
    int sm = sumarr[k-1];
    int r = k;
    for(int i = k ; i < n ;i++){
            cout<<sm<<" ";
            sm = sm-arr[i-r]+arr[i]+sumarr[i-r];
            cout<<sm<<" "<<arr[i-r]<<" "<<arr[i]<<" "<<sumarr[i-r]<<endl;
        
    }
    return sm;
}
int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<sol(arr,n,k);
}