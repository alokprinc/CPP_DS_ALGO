#include<iostream>
using namespace std;
int main(){
   int n,s;
    cin>>n>>s;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
   int sum = 0,end = 0;
   int j = 0;
  while (j<n && sum <= s)
  {
      sum = sum + arr[j];
      j++;
      
  }
    end = j;
    int i = 0;
    while (i<n && sum>=s)
    {
        sum = sum - arr[i];
        i++;
    }
    int start = i;

    if( start == end){
        cout<< end;
    } 
    
    else{
    cout<<start<<" "<<end;
}  

}
