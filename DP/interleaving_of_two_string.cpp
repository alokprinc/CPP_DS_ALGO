#include <bits/stdc++.h>
using namespace std;
bool sol(string a,string b,string c,int i,int j,int k){

    if(k == c.length()-1){
        return true;
    }
    if(a[i] == c[k]){
       bool x = sol(a,b,c,i+1,j,k+1);
       if(x) return true;
    }
    if(b[j] == c[k]){
       bool y = sol(a,b,c,i,j+1,k+1);
       if(y) return true;
    }
    if((a[i] == c[k]) and ( b[j] == c[k])){
        bool z = sol(a,b,c,i+1,j,k+1) or sol(a,b,c,i,j+1,k+1);
        if(z) return true;
    }
    return false;
}
bool sol2(string a,string b,string c){
    
}
int main()
{
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    // sol(a, b, c,0,0,0) ? cout << "true" : cout << "false";
}