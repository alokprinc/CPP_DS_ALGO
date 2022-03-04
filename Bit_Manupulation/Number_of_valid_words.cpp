#include<bits/stdc++.h>
using namespace std;

vector<int> findNumOfValidWords(vector<string> &words,vector<string> &puzzles)
{   vector<int> vec;
    unordered_map<char, vector<int>> mp;
    for(int i = 0 ; i < 26;i++){
        mp.insert({'a'+i,vec});
    }

    for(auto word: words){
        int wmask = 0;
        for(auto ch:word){
            int bit = ch - 'a';
            wmask = wmask | (1 << bit);
        } 
        unordered_set<char> uq;
        for(auto ch: word){
            if(uq.find(ch) != uq.end()){
                continue;
            }
            uq.insert(ch);
            mp[ch].push_back(wmask);
        }
    }
    vector<int> result;
    for(auto puzzel:puzzles){
       int pmask = 0;
       for(char ch : puzzel){
           int bit = ch - 'a';
           pmask = pmask | (1<<bit);
       }
        int count =0;
       char fch = puzzel[0];
       vector<int> arr = mp[fch];
       for(auto wmask:arr){
           if((wmask & pmask) == wmask){
               count++;   
           }
       }
       result.push_back(count);

    }
    return result;
}

int main()
{
    int n;cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;++i) cin>>words[i];
    int m;cin>>m;
    vector<string> puzzles(m);
    for(int i=0;i<m;++i) cin>>puzzles[i];
    vector<int> ans=findNumOfValidWords(words,puzzles);
    for(int i=0;i<m;++i) 
        cout<<puzzles[i]<<" -> "<<ans[i]<<"\n";
    return 0;
}