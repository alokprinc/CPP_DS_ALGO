#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
int mn = INT_MAX;
void sol(vector<int> arr, vector<int> set1, vector<int> set2, int idx, int s1, int s2)
{
    if (idx == arr.size())
    {
        if(s1 > 0 and s2 > 0 and abs(s1-s2) < mn ){
            mn = abs(s1-s2);
            ans.push_back(set1);
            ans.push_back(set2); 
        }
        return;
    }
    if (set1.size() < (arr.size() + 1) / 2)
    {
        set1.push_back(arr[idx]);
        sol(arr, set1, set2, idx + 1, s1 + arr[idx], s2);
        set1.pop_back();
    }
    if (set1.size() < (arr.size() + 1) / 2)
    {
        set2.push_back(arr[idx]);
        sol(arr, set1, set2, idx + 1, s1, s2 + arr[idx]);
        set2.pop_back();
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> set1, set2;
    sol(arr, set1, set2, 0,0,0);
    
        cout<<"[";
        for(int i = 0 ; i < ans[ans.size()-2].size(); i++){
            if(i != ans[ans.size()-2].size()-1){
                cout<<ans[ans.size()-2][i]<<", ";
            }else{
                cout<<ans[ans.size()-2][i];
            }
        }
        cout<<"] ";
        cout<<"[";
        for(int i = 0 ; i < ans[ans.size()-1].size(); i++){
            if(i != ans[ans.size()-1].size()-1){
                cout<<ans[ans.size()-1][i]<<", ";
            }else{
                cout<<ans[ans.size()-1][i];
            }
        }
        cout<<"] ";
        
}