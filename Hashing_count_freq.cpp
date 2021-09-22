#include<bits/stdc++.h>
using namespace std;

void count_freq(vector<int> arr){
    map<int,int> m;
int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    
    map<int,int> :: iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout<<it->first<<" -> "<<it->second<<endl;;
    }

}
int main(){

vector<int> arr = { 1,2,1,3,2};
count_freq(arr);

}