#include<bits/stdc++.h>
using namespace std;
void sol(vector<int> &arr,int n){
    int n3 = 0;
    int n31 = 0;
    int n32 = 0;
    for(int i = 0 ; i < n; i++){
        n3 = (1 << i);
    }
    int cn3 = 0;
    int cn31 = 0;
    int cn32 = 0;
    for(auto a: arr){
        cn3 = (a & cn3);
        cn31 = (a & cn31);
        cn32 = (a & cn32);

        n31 = (n31 | cn3);
        n32 = (n32 | cn31);
        n3 = (n3 | cn32);

    }
    cout<<n31<<endl;
}
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

        n3 = (n3 & (~cn3));
        n31 = (n31 | cn3);
        
        n31 = (n31 & (~cn31));
        n32 = (n32 | cn31);
        
        n32 = (n32 & (~cn32));
        n3 = (n3 | cn32);
        

    }
    cout<<n31;
}