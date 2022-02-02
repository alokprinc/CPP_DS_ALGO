#include <bits/stdc++.h>
using namespace std;

void combination(int cc,int ts, string uq, int ssf,unordered_map<char,int> st,string ans)
{
  if(cc == ts){
      if(ssf == ans.length())
       cout<<ans<<endl;
     return;
  }
  
  for(int i = 0; i < uq.length();i++){
      char  ch = uq[i];
      if(st[ch] > 0){
          st[ch]--;
          combination(cc+1,ts,uq,ssf+1,st,ans+ch);
          st[ch]++;
      }
  }
}
int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    
    unordered_map<char,int> st;
    string ustr="";
    for(int i=0;i<str.size();i++)
    {
        char ch=str[i];
        if(st.find(ch)==st.end())
        {
            st[ch]++;
            
            ustr+=ch;
        }else{
            st[ch]++;
        }
    }
// for(auto a:st){
//     cout<<a.first<<" -> "<<a.second<<endl;
// }
    combination(0,k, ustr, 0, st,"");
    return 0;
}