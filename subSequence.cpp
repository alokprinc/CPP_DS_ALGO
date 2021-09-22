#include <bits/stdc++.h>
using namespace std;
 vector<string> v;
 void subSequence(string s, string ans,int k)
{
   
    if (s.length() == 0)
    {
        //if(ans.size() >= k){
        //cout << ans << endl;
        v.push_back(ans);
       // }
        return;
    }
    char ch = s[0];
    string remainingString = s.substr(1);

    subSequence(remainingString, ans + ch,k);
    subSequence(remainingString, ans,k);
}

int fun()
{
    subSequence("1110011011", "",0);
 
    unordered_set<string> st;
     for(auto i : v)
    st.insert(i);

    for(auto i : st)
    cout<<i<<endl;
    
    int count  = st.size()-1;
    for(auto i:st){
        if( i.length()>1 && i[0] == '0'){
            count  = count - 1;
        }
    }
    return count;
}
int main(){
    cout<<fun();
}