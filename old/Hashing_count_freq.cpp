#include<bits/stdc++.h>
using namespace std;

// void count_freq(vector<int> arr){
//     map<int,int> m;
// int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         m[arr[i]]++;
//     }
    
//     map<int,int> :: iterator it;
//     for (it = m.begin(); it != m.end(); it++)
//     {
//         cout<<it->first<<" -> "<<it->second<<endl;;
//     }

// }
void cf(string A){
    
     unordered_map<char,int> mp;
    vector<pair<char,int>> v;
    for(int i = 0; i < A.length()-1;i++){
        mp[A[i]]++;
    }
    unordered_map<char,int> :: iterator it;
    for(it = mp.begin(); it != mp.end();it++){
        cout<<it->first<<"->"<<it->second<<endl;
        v.push_back({it->first,it->second});
    }
 
    int N=0;
    for(int i = mp.size(); i >=0;i--){
        if(v[i].second>1){
            N+=v[i].second;
        }
        if(v[i].first == A[0] and v[i].second >N/3){
            cout<<"gold";
        }
    }

}
int main(){
string s = "abcd";
// vector<int> arr = { 1,2,1,3,2};
// count_freq(arr);
cf(s);
}