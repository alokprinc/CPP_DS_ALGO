#include<iostream>
 #include<vector>
 using namespace std;
 
 vector<string> grayCode(int n) {
 	 
      vector<string> callback = grayCode(n-1);

      vector<string> ans;
 }
     
 
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<string> res = grayCode(n);
     cout<<"[";
     for(int i=0; i<res.size(); i++){
         cout<<res[i];
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
 }