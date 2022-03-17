#include<bits/stdc++.h>
using namespace std;
void sol(vector<int> &arr,int n){
    int currsum(arr[0]),overallsum(arr[0]);
    for(int i = 1; i < n ; i++){
        if(currsum >= 0){
            currsum+=arr[i];
        }else{
            currsum = arr[i];
        }
       
        overallsum = max(currsum,overallsum);
    }
    cout<<overallsum;
}
int  main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    sol(arr,n);
}