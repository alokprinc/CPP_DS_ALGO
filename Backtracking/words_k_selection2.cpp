#include <bits/stdc++.h>
using namespace std;

void combination(int lval, string uq, int ssf, int ts, string ans )
{
  
  if(ssf==ts){
      cout<<ans<<endl;
      return;
  }
  for(int i = lval+1; i < uq.length();i++){
      char ch = uq[i];
      combination(i,uq,ssf+1,ts,ans+ch);
      
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
    combination(-1, ustr, 0, k, "");
    return 0;
}