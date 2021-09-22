#include<iostream>
#include<climits>
using namespace std;

int main(){
   int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

   
    const int N = 1e5+2;
    int idx[N];
    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }
int min = INT_MAX;
    
  for (int i = 0; i < n; i++)
  {
      if(idx[i] != -1){
        //  min = max(min, idx[i]);
        min = idx[i];
      } else{
          idx[arr[i]] = i;
      }
  }
   if(min == INT_MAX){
cout<< -1;
   } else{
       cout<< min -1 << endl;
   }


}
