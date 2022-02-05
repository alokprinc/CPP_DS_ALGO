#include<bits/stdc++.h>
using namespace std;
    void sol(unordered_map<char,int> mp,string uq,int idx,string asf,string odd,int ts){
        if(idx > ts){
            if(asf.length()==ts){
            string rasf = asf;
            reverse(rasf.begin(),rasf.end());
            cout<<asf<<odd<<rasf<<endl;
            }
            return;
        }
        
        for(int i = 0 ; i < uq.length();i++){
            if(mp[uq[i]] > 0){
                mp[uq[i]]--;
                sol(mp,uq,idx+1,asf+uq[i],odd,ts);
                mp[uq[i]]++;
            }
        }
    }
	int main() {
        string str;
        cin >> str;
        
    unordered_map<char,int> mp;
    string uq;
    for(int i = 0 ; i < str.length(); i++){
        if(mp.find(str[i]) == mp.end()){
        
        uq+=str[i];
        }
        mp[str[i]]++;
    }
    string odd;
    for(int i = 0 ; i < str.length(); i++){
        if(mp[str[i]]%2 != 0 and odd[0] != str[i]){
            odd+=str[i];
        }
    }
    if(odd.size() > 1){
        cout<<"pallindrome not possible"<<endl;
        return 0;
    }
    int len = 0;
    for(int i = 0 ; i  < uq.size();i++){
        mp[uq[i]] /=2;
        len+=mp[uq[i]];
    }
   
  //  sort(uq.begin(),uq.end());
    sol(mp,uq,1,"",odd,len);
        return 0;
    }