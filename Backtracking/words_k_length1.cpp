#include <bits/stdc++.h>
using namespace std;

void combination(int cc,int ts, string uq, int ssf,vector<char> spots)
{
  if(cc == uq.length()){
      
      if(ssf == ts){
          for(auto a: spots){
              cout<<a;
          }cout<<endl;
      }
      return;
  }
  char ch = uq[cc];
  for(int i = 0; i < spots.size();i++){
      if(spots[i] == 0){
          spots[i] = ch;
          combination(cc+1,ts,uq,ssf+1,spots);
          spots[i]= 0;
      }
  }
  combination(cc+1,ts,uq,ssf,spots);
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
    combination(0,k, ustr, 0, spots);
    return 0;
}