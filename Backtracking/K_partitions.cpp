#include<bits/stdc++.h>
using namespace std;
int c = 0;
void sol(int n,int k,int i,int ssf,vector<vector<int>> &ans){
if(i > n){
    if(ssf == k){
        c++;
        cout<<c<<". ";
        for(auto a:ans){
            cout<<"[";
            for(int j = 0; j < a.size();j++){
                if(a.size()==1){
                   cout<<a[j];
                }else{
                    if(j == a.size()-1){
                    cout<<a[j];
                    }
                    else{
                        cout<<a[j]<<", ";
                    }
                }

                
            }
            cout<<"] ";
        }cout<<endl;
    }
    return;
}
    for(int j = 0 ; j < ans.size();j++){

        if(ans[j].size() > 0){
            ans[j].push_back(i);
            sol(n,k,i+1,ssf,ans);
            ans[j].pop_back();
        }else{
            ans[j].push_back(i);
            sol(n,k,i+1,ssf+1,ans);
            ans[j].pop_back();
            break;
        }
    }
}
int main(){
    int n,k;
    cin>>n>>k;

vector<vector<int>> arr(k); 
    sol(n,k,1,0,arr);

}
