#include<bits/stdc++.h>
using namespace std;
// method 1
//int t[1001][1001][2];

// method 2
static unordered_map<string,int> mp;
mp.clear;
int boolean_exp_par(string s,int i ,int j,bool isTrue){
    if(i > j )
    return false;

    if(i == j){
        if(isTrue == true)
        return s[i] == 'T';

        else
        return s[i] == 'F';
    }
    //method 2
    // string temp = to_string(i);
    // temp.push_back(' ');
    // temp.append(to_string(j));
    // temp.push_back(' ');
    // temp.append(to_string(isTrue));

    
    // if(mp.find(temp) != mp.end()){
    //     return mp[temp];
    // }
  //  method 1
    if(t[i][j][isTrue] != -1){
        return t[i][j][isTrue];
    }
   int ans = 0;

    for(int k = i + 1; k <= j - 1; k=k+2){
        int rf,rt,lf,lt;
        lf = boolean_exp_par(s,i,k-1,false);
        lt = boolean_exp_par(s,i,k-1,true);
        rf = boolean_exp_par(s,k+1,j,false);
         rt = boolean_exp_par(s,k+1,j,true);
        // method 1
        // if(t[i][k-1][isTrue] != -1){
        //     lf = t[i][k-1][isTrue];
        // }else{
        //   lf = boolean_exp_par(s,i,k-1,false);
        //  // t[i][k-1][false] = lf;
        // }

        // if(t[i][k-1][isTrue] != -1){
        //     lt = t[i][k-1][isTrue];
        // }else{
        //   lt = boolean_exp_par(s,i,k-1,true);
        //   //t[i][k-1][true] = lt;
        // }

        // if(t[k+1][j][isTrue] != -1){
        //    rf = t[k+1][j][isTrue];
        // }else{
        //    rf = boolean_exp_par(s,k+1,j,false);
        //  // t[k+1][j][false] = rf;
        // } 

        // if(t[k+1][j][isTrue] != -1){
        //     rt = t[k+1][j][isTrue];
        // }else{
        //   rt = boolean_exp_par(s,k+1,j,true);
        // //  t[k+1][j][true] = rt;
        // } 

            if(s[k] == '&'){
                if(isTrue == true)
                ans = ans + lt * rt;

                else
                ans = ans + lt * rf + lf * rf + lf * rt;
            }
            else if(s[k] == '|'){
                if(isTrue == true)
                ans = ans + lt * rf  + lf * rt + lt * rt;

                else
                ans = ans + lf * rf;
            }
            else if(s[k] == '^'){
                if(isTrue == true)
                ans = ans + lt * rf  + lf * rt ;

                else
                ans = ans + lf * rf + lt * rt;
            }
    }
    return mp[temp] = ans;

}

int main(){
    string a = "TTFT";
    string b = "|&^";
    int n = a.size()+b.size();
    char s[n];
    int i = 0,j = 0, k = 0;
    while(i < n || k < a.size() || j < b.size())
    {
        s[i] = a[k];
        i++;
       k++;
        s[i] = b[j];
       i++;
        j++;
        
    }

    for(auto i : s ){
        cout<< i <<" ";
    }
    cout<<endl;
   // memset(t,-1,sizeof(t));
    cout<<boolean_exp_par(s,0,n-1,true);
}