#include<bits/stdc++.h>
using namespace std;
void words(string s,unordered_map<char,int> &mp,string ans,set<char> uset){
if(ans.length()==s.length()){
    cout<<ans<<endl;
    return;
}

    for(auto a:uset){
        if(mp[a] > 0){
            mp[a]--;
           
            words(s,mp,ans+a,uset);
            mp[a]++;
        }
    }
}
int main(){
    string s;
    getline(cin,s);
    string uq;
    set<char> uset;
    unordered_map<char,int> mp;
    for(int i = 0; i < s.length();i++){
        mp[s[i]]++;
        uset.insert(s[i]);  
    }
    words(s,mp,"",uset);
}