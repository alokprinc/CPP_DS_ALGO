#include<bits/stdc++.h>
using namespace std;
bool sol(vector<int> stone,int n){
    map<int,set<int>> mp;

    for(int i = 0 ; i < n;i++){
        set<int> st;
        mp.insert({stone[i],st});
    }
    mp[stone[0]].insert(1);

    for(int i = 0 ; i < n ; i++){
        set<int> jumps = mp[stone[i]];
        for(auto jump:jumps){
            int afterjump = jump+stone[i];
            if(afterjump == stone[n-1]){
                return true;
            }
            if(mp.find(afterjump) != mp.end()){
                if(afterjump-1 > 0){
                mp[afterjump].insert(jump-1);
                }
                mp[afterjump].insert(jump);
                mp[afterjump].insert(jump+1);
            }

        }
    }
    return false;
}
int main(){
    int n; cin>>n;
    vector<int> stone(n);
    for(int i = 0 ; i < n ; i++){
        cin>>stone[i];
    }
    sol(stone,n)?cout<<"true":cout<<"false";
}