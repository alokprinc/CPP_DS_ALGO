#include<bits/stdc++.h>
using namespace std;
int longestSubsequence( vector<int> arr,int n)
    {
       int t[n];
        memset(t,0,sizeof(t));
       int omax = 0;
       for(int i = 0; i < n;i++){
           int max=0;
           for(int j = 0; j < i ; j++){
               if(arr[i] > arr[j]){
                   if(t[j] > max){
                       max = t[j];
                   }
               }
           }
           t[i] = max+arr[i];
           cout<<t[i]<<endl;
           if(omax < t[i])
           omax = t[i];
       }
       return omax;
    }

int main(){
        vector<int> A={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};

     int n = A.size();
     cout<<longestSubsequence(A,n);
    }