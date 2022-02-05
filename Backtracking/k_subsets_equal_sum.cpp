#include <bits/stdc++.h>
using namespace std;

void sol(int n,int k,vector<int> arr,vector<vector<int>> &ans,int i,int ssf,vector<int> &subsum){

if(i == n-1){
if(ssf == k){
    
    int ts = 0;
    for(auto a:ans){
        int s = 0;
        for(int j = 0 ; a.size();j++){
            s+=a[j];
        }
        subsum.push_back(s);
    }
    for(int j = 0 ; j < subsum.size();j++){
        if(j < subsum.size()-1)
        if(subsum[j] != subsum[j+1]){
            return;
        }
    }
    for(auto a:ans){
            cout<<"[";
            for(int j = 0; j < a.size();j++){
                if(a.size()==1){
                   cout<<a[j];
                }else{
                    if(j == a.size()-1){
                    cout<<a[j];
                    }
                    else{
                        cout<<a[j]<<", ";
                    }
                }

                
            }
            cout<<"] ";
        }cout<<endl;
}
return;
}
    for(int j = 0; j < ans.size();j++){
        if(ans[j].size() > 0){
            ans[j].push_back(arr[i]);
            sol(n,k,arr,ans,i+1,ssf,subsum);
             ans[j].pop_back();
        }else{
            ans[j].push_back(arr[i]);
            sol(n,k,arr,ans,i+1,ssf+1,subsum);
            ans[j].pop_back();
            break;
        }
    }
}
int main()
{
    int n;
    vector<int> arr(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int k;
    cin >> k;
    if (k == 1)
    {
        cout << "[";
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << ", ";
        }
        cout << "]";
        return 0;
    }
    // if there are more subsets than no. of elements in array or sum of all elements is not divisible by k
    if (k > n || sum % k != 0)
    {
       cout<<"-1";
        return 0;
    }
  vector<int> subsum;  
   vector<vector<int>> ans(k);
    sol(n,k,arr,ans,0,0,subsum);
}