#include <bits/stdc++.h>
using namespace std;
void sol(vector<int> &arr,int n){
    int sum = 0;
    int r=1;
    for(int i = n-2;i>=0;i++){
        sum+= (arr[i-1]*arr[i]*arr[i+r]);
        r+=1;
    }
    sum += arr[n-1];
    cout<<sum<<endl;
}
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    for(auto a: arr){
        cout<<a<<" ";
    }
    sol(arr,n);
}