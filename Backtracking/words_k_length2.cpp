#include <bits/stdc++.h>
using namespace std;

void combination(int cc,int ts, string uq, int ssf,unordered_set<char> st,string ans)
{
  if(cc == ts){
     cout<<ans<<endl;
     return;
  }
  
  for(int i = 0; i < uq.length();i++){
      char  ch = uq[i];
      if(st.find(ch) == st.end()){
          st.insert(ch);
          combination(cc+1,ts,uq,ssf+1,st,ans+ch);
          st.erase(ch);
      }
  }
}
int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    set<char> unique;
    string ustr="";
    for(int i=0;i<str.size();i++)
    {
        char ch=str[i];
        if(unique.find(ch)==unique.end())
        {
            unique.insert(ch);
            ustr+=ch;
        }
    }
    vector<char> spots(k,0);
    unordered_set<char> st;
    
    combination(0,k, ustr, 0, st,"");
    return 0;
}