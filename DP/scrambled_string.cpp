#include<bits/stdc++.h>
using namespace std;
bool sol(string s1,string s2,int si1,int si2,int len){
    if(s1.substr(si1,si1+len)==(s2.substr(si2,si2+len))){
        return true;
    }
    
    for(int i = 1 ; i < len; i++){
        if((sol(s1,s2,si1,si2,i) and sol(s1,s2,si1+i,si2+i,len-1)) or
           ( sol(s1,s2,si1,si2+len-i, i) and sol(s1,s2,si1+i,si2,len-i))){
                return true;
            }
    }
    return false;
}
int main(){
string s1,s2;
getline(cin,s1);
getline(cin,s2);

cout<<sol(s1,s2,0,0,s1.length());
}