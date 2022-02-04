#include<bits/stdc++.h>
using namespace std;
int stringSum(string s,unordered_map<char,int> mp){
    string sum_s1="";
    for(int i = 0; i < s.length();i++){
            sum_s1 += to_string(mp[s[i]]);
    }
    stringstream geek(sum_s1);
    int x;
    geek >> x;
    return (x);
}
void solve(string s1,string s2,string s3,string uq,unordered_map<char,int> mp,vector<int> check,int idx){
    if(idx == uq.length()){
        int sum_s1 = stringSum(s1,mp);
        int sum_s2 = stringSum(s2,mp);
        int sum_s3 = stringSum(s3,mp);
        
        if(sum_s1+sum_s2 == sum_s3){
            for(int i = 0; i < 26;i++){
                char ch = (char)('a'+i);
                if(mp.find(ch)!=mp.end()){
                    cout<<ch<<"-"<<mp[ch]<<" ";
                }
            }
            cout<<endl;
        }
      return;  
    }
    char ch = uq[idx];
    for(int i = 0 ; i <= 9;i++){
        if(check[i] == 0 ){
            check[i] = 1;
            mp[ch] = i;
            solve(s1,s2,s3,uq,mp,check,idx+1);
            mp[ch] = -1;
            check[i]=0;
        }
    }
   
}
int main(){
    string s1,s2,s3;
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);

    unordered_map<char,int> mp;
    string uq;

    for(int i = 0; i < s1.length();i++){
        if(mp.find(s1[i]) == mp.end()){
            mp.insert({s1[i],-1});
            uq += s1[i];
        }
    }
    for(int i = 0; i < s2.length();i++){
        if(mp.find(s2[i]) == mp.end()){
            mp.insert({s2[i],-1});
            uq += s2[i];
        }
    }
    for(int i = 0; i < s3.length();i++){
        if(mp.find(s3[i]) == mp.end()){
            mp.insert({s3[i],-1});
            uq += s3[i];
        }
    }
    vector<int> check(10,0);
    solve(s1,s2,s3,uq,mp,check,0);
    
}