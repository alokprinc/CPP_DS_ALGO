#include<bits/stdc++.h>
using namespace std;

int min_coins(vector<int> arr,int  x){
    sort(arr.begin(),arr.end(), greater<int>());
    int n = arr.size();
    int ans = 0;
    for(int i = 0; i < n ; i++){
      ans += x/arr[i];
      x -= x/arr[i]*arr[i];
       
    }
    return ans;
}
int main(){
    int x = 35003154;
    vector<int> arr = {1,2,5,10,20,50,100,200,500,2000};
    cout<<min_coins(arr,x);
}