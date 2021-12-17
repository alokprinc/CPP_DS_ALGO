#include<bits/stdc++.h>
using namespace std;

void longestConsecutive(vector<int>& num) {

    unordered_map<int,bool> mp;
    for(auto a: num){
        mp[a] = true;
    }

    for(auto a: num){
        if(mp.find(a-1)!=mp.end()){
            mp[a] = false;
        }
    }
    
    int mval = INT_MIN;
    int mseq = INT_MIN;
    for(auto a: num){
        if(mp[a]==true){
            int val = a;
            int seq = 1;
            while(mp.find(val + seq) != mp.end()){
                seq++;
                
            }
            if(seq > mseq){
                mseq = seq;
                mval = val;
            }
            
        }
    }
    for(int i = 0; i < mseq; i++){
         cout<<mval + i<<endl;
    }

}

int main()
{
  vector<int>arr;
  int n;
  cin >> n;
  for (int i = 0 ; i < n; i++) {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  longestConsecutive(arr);

  return 0;
}