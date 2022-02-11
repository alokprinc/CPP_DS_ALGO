#include <iostream>
using namespace std;

int searchNumber(int arr[], int n, int i,int key){
        if(i==n){
            return -1;
        }
        if(arr[i]==key){
           return i;
        }
return  searchNumber(arr,n,i+1,key);
}
int lastOccurence(int arr[], int n, int i,int key){
      int restArray = lastOccurence(arr,n,i+1,key);
      
      if(restArray !=-1){ 
      return restArray;
      }
      if(arr[i]==key){
          return i;
      }
      return -1;
}
int main(){
   int arr[]={1,2,3,2,3,2,5};
   
   cout<< searchNumber(arr,7,0,2);
   cout<< lastOccurence(arr,7,0,2);
  
}