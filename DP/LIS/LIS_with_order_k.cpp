#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> a,b;
unordered_map<string ,int> mp;
int fun(int i,int j,int k){
	if( i == n || j == m)
	return 0;

	int c1(0),c2(0),c3(0);
    string temp = to_string(i)+" "+to_string(j)+" "+to_string(k);
    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }
	if(a[i] == b[j]){
		c1 =1 + fun(i+1,j+1,k);
	}
	if(k>0){
		c2 = 1+ fun(i+1,j+1,k-1);
	}
	c3 = max(fun(i+1,j,k),fun(i,j+1,k));

	return mp[temp] = max({c1,c2,c3});
}    
int main(){
	cin>>n>>m>>k;
	a = vector<int>(n);
	b = vector<int>(m);
    
	for(auto &i : a)
	cin>>i;

	for(auto &j : b)
	cin>>j;

	cout<<fun(0,0,k);
}

