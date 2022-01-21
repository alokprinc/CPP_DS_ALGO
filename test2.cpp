/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;
void sol(string s,int i,int n,vector<vector<string>> &arr,string ans){
	if(i == n){
		
		for(int i = 0 ; i < n;i++){
			if(ans.length() == i){
				arr[i].push_back(ans);
			}
		}
		
	//	cout<<ans<<endl;
		return;
	}
	
	char ch = s[i];
	sol(s,i+1,n,arr,ans+ch);
	sol(s,i+1,n,arr,ans);
}
int main() {
	int num;
	cin >> num;										
	string s;
	cin>>s;
	vector<vector<string>> arr(num,vector<string>());
	string ans;
	
		
	sol(s,0,num,arr,"");
	vector<vector<int>> fn(num,vector<int>(3,0));
	for(int i = 0; i < num;i++){
		string sh = s.substr(0,i+1);
		for(auto a:arr[i]){
			if(sh.compare(a) > 0){
				fn[i][0]++;
			}
			if(sh.compare(a) == 0){
				fn[i][1]++;
			}
			if(sh.compare(a) < 0){
				fn[i][2]++;
			}
		}
	}
	for(auto a:arr){
		for(auto b:a)
		cout<<b<<" ";
		cout<<endl;
	}
	for(auto a:fn){
		for(auto b:a){
			cout<<b<<" ";

		}cout<<endl;
	}
	return 0;

}