#include<bits/stdc++.h>
using namespace std;

string print_pallindrome_seq(string x,string y,int n,int m){
    int t[n+1][m+1];
    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0 ; j < m+1; j++){
            if(i == 0 || j == 0)
            t[i][j] = 0;
        }
    }

    for(int i = 1; i < n +1 ; i++){
        for(int j = 1 ; j < m + 1 ; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1],t[i-1][j]);
            }
        }
    }

    int i = n+1, j = m+1;
    string ans;
    while(i > 0 , j > 0){
        if(x[i - 1] == y[j-1]){
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1] > t[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    ans.pop_back();
    return ans;
}
int fun(string x,int n,int m){
    if(n==1){
        cout<<x;
        return 1;
    }
    int dp[n][m];
    int len =0,s(0),e(0);
    for(int g = 0; g < n; g++){
        for(int i = 0 , j = g; j < n; i++,j++){
            if(g == 0){
                dp[i][j] = 1;
            }
            else if(g == 1){
                if(x.at(i) ==x.at(j))
                dp[i][j] =1;

                else
                dp[i][j] = 0;
            }
            else{
                if(x.at(i) ==x.at(j) and dp[i+1][j-1]==1)
                dp[i][j] =1;

                else
                dp[i][j] = 0;
            }
            if(dp[i][j]){
                len = g+1;
                cout<<i<<" "<<j<<" "<<g<<endl;
                if(g == len-1){
                    s=i;
                    e=j;
                }
            }
           
        }
    }
    string ans;
    for(int i =s; i<=e;i++){
        ans.push_back(x[i]);
    }
    cout<<x.substr(s,e);
    return len;
}
int print_pallindrome_subString(string x,string y,int n,int m){
    int t[n+1][m+1];
    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0 ; j < m+1; j++){
            if(i == 0 || j == 0)
            t[i][j] = 0;
        }
    }
    int result = 0;
    int row,col;
    for(int i = 1; i < n +1 ; i++){
        for(int j = 1 ; j < m + 1 ; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                if(result <t[i][j]){
                     result = max(result,t[i][j]);
                     row = i;
                     col = j;
                }
            }
            else{
                t[i][j] = 0;
            }
        }
    }

 string ans;
while(result){
    ans.push_back(x[row-1]);
    row--;
    result--;
}
cout<<ans<<endl;

    return result;
}
int main(){
    string x = "ac";
    string y = x;
    reverse(y.begin(),y.end());
    int n = x.size();
    int m = y.size();
    // cout<<"pallindromic sequence is ->  "<<print_pallindrome_seq(x,y,n,m)<<endl;
    cout<<"size of pallindrome ->  "<<print_pallindrome_seq(x,y,n,m).size()<<endl;
    //  cout<<"pallindromic sub string is ->  "<<print_pallindrome_subString(x,y,n,m)<<endl;
    //cout<<"size of sub string pallindrome ->  "<<print_pallindrome_subString(x,y,n,m).size()<<endl;
    cout<<fun(x,n,m);
}