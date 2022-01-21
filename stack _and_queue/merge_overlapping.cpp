#include<bits/stdc++.h>
using namespace std;

struct myComp{
   bool operator()(
       pair<int,int> &x,
       pair<int,int> &y
   ){
      return x.first > y.first;
    }
};
void mergeOverlappingIntervals(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<pair<int,int>> p;
    for(int i = 0; i < arr.size(); i++){
        p.push_back({arr[i][0],arr[i][1]});
    }
    sort(p.begin(),p.end());
    stack<pair<int,int>> st;
    st.push(p[0]);
    for(int i = 1 ; i < n;i++){
        if(p[i].first > st.top().second){
            st.push(p[i]);
        }
        else{
           if(st.top().second < p[i].second){
               st.top().second = p[i].second;
           }
        }
    }
    vector<pair<int,int>> ans;
    while(st.size() > 0){
        ans.push_back(st.top());
        st.pop();
    }
    sort(ans.begin(),ans.end());
    for(auto a: ans){
        cout<<a.first<<" "<<a.second<<endl;
    }

}

int main() {
  int n;
  cin >> n ;

  vector<vector<int>> arr( n, vector<int>(2) );



  // input
  for (int i = 0; i < n ; i++ ) {
    cin >> arr[i][0];
    cin >> arr[i][1];
  }


  mergeOverlappingIntervals(arr);

}