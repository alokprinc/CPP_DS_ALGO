#include<iostream>
using namespace std;

int peakElement(int arr[],int start,int end){
    if (start>end)
    {
        return -1;
    }
    int prev = start,curr = start+1,next = curr+1;
    int ans = 0;
    while (next!=end)
    {
        if (arr[curr]>arr[prev] && arr[curr] > arr[next])
        {
             ans =  arr[curr];
             return ans;
        }
        else{
            prev = curr;
            curr = next;
            next = curr+1;
        }
        
    }
    return -1;
}

int peakElementB(int arr[], int low,int high,int n){
    if(low>high){
        return -1;
    }
        int  mid = low + (high-low)/2; // remain with in int range 
    if ((mid == n -1 || arr[mid+1] <= arr[mid]  ) && ( mid == 0 || arr[mid -1] <= arr[mid]))
    {
        return arr[mid];
    }
    else if(mid > 0  && arr[mid] < arr[mid - 1]){
        return peakElementB(arr,low,mid-1,n);
    }else{
        return peakElementB(arr,mid+1,high,n);
    }
    

}

int main(){
   int arr[] = {2,4,5,20,19,10};
   
   cout<<peakElement(arr,0,5)<<endl;
    cout<<peakElementB(arr,0,5,5);
    return 0;
}