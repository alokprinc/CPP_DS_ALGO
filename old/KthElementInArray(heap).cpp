#include<bits/stdc++.h>
using namespace std;

int KthLargestElement(vector<int> arr,int k){
    priority_queue<int,vector<int>> maxHeap;
    if(k == 0){
        return -1;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        maxHeap.push(arr[i]);
    }

    for (int i = 0; i < k-1; i++)
    {
        maxHeap.pop();
    }
    return maxHeap.top();
     
}

int KthSmallestElement(vector<int> arr,int k){
    priority_queue<int,vector<int>,greater<int>> minHeap;
    if(k == 0){
        return -1;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        minHeap.push(arr[i]);
    }

    for (int i = 0; i < k-1; i++)
    {
        minHeap.pop();
    }
    return minHeap.top();
     
}
int main(){
    vector<int> arr = {2,6,4,5,3,9,1,7};
    int  k = 3;
    cout<<KthLargestElement(arr,k)<<endl;
    cout<<KthSmallestElement(arr,k);
}