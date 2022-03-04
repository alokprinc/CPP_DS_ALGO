#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0 ; i < n;i++){
        cin>>arr[i];
        
    }
  // sol(arr,n);
    int n3 = INT_MAX;
    int n31 = 0;
    int n32 = 0;
    // for(int i = 0 ; i < n; i++){
    //     n3 = (1 << i);
    // }
    int cn3(0),cn31(0),cn32(0);
    for(auto a: arr){

        int cn3 = (a & cn3);
        int cn31 = (a & cn31);
        int cn32 = (a & cn32);

       
        
        int tn31 = (n31 & (~cn31));
        tn32 = (tn32 | cn31);
        
        int tn32 = (n32 & (~cn32));
        tn3 = (tn3 | cn32);
        
        int tn3 = (n3 & (~cn3));
        tn31 = (tn31 | cn3);
    }
    cout<<n31;
}