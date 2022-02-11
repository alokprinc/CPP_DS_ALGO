#include<iostream>
using namespace std;
int main(){
   int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int rbd=0;
    int mx = -1;
   for (int i = 0; i < n; i++)
   {
       if(n == 1){
           return 1;
       }

       if(arr[i] > arr[i+1] && arr[i] > mx){
           rbd++;
           mx = arr[i];  
       } 

       //mx = max(arr[i],mx);
   }
   cout<< rbd;
}