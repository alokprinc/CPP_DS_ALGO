#include<bits/stdc++.h>
using namespace std;

int main(){
	
	
  int n1,n2;
  cin>>n1;
  int arr1[n1];
  unordered_map<int,int> mp;
  for(int i = 0; i < n1;i++){
    cin>>arr1[i];
    mp[arr1[i]]++;
  }
  cin>>n2;
  int arr2[n2];
  for(int i = 0 ; i < n2; i++){
    cin>>arr2[i];
    if(mp[arr2[i]]){
        if(mp[arr2[i]] > 0){
        mp[arr2[i]]--;
        cout<<arr2[i]<<endl;
        }
    }  
  }


	
}