#include <iostream>
#include<climits>
using namespace std;

//  Kadanes Sum Function //
int kadane(int arr[], int n){

    int currentSum = 0;
    int mx = 0;
for (int i = 0; i < n; i++)
{
     currentSum += arr[i]; 

    if(currentSum < 0){
        currentSum = 0;
    } 
     mx = max(currentSum, mx);
}
return mx;

}
  // total sum function //
int totalArraySum(int arr[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum ;
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
 int nonWrapSubArraySum = kadane(arr,n);

 int totalSum = totalArraySum(arr,n);
for (int i = 0; i < n; i++)
{
    arr[i] = -arr[i];
}
 int wrapMaxSubArraySum = totalSum +  kadane(arr,n);

 cout<<max(wrapMaxSubArraySum,nonWrapSubArraySum);

}

