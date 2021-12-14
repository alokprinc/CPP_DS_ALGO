#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string str;
  cin >> str;

 unordered_map<char,int> mp;

 for(int i = 0; i < str.length(); i++){
   mp[str[i]]++;
 }
  int mx = INT_MIN;
 char ch ;
 for(auto a: mp){
     if(a.second > mx){
         mx = a.second;
         ch = a.first;
     }
 }
 cout<<ch;
 
 
 }
  
