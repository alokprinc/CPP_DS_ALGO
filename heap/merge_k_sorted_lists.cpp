#include<bits/stdc++.h>
using namespace std;
class Pair{
    public:

    int index;
    int val;
    int listnumber;
    Pair(int index,int val,int listnumber){
        this->val = val;
        this->listnumber = listnumber;
        this->index = index;
    }
};
struct myComp{
    bool operator()(
        Pair &a,
        Pair &b
    )
    { 
        return a.val > b.val; 
    }
};
vector<int>mergeKSortedLists(vector<vector<int>>&lists) {
  vector<int> rv;
   //write your code here
   priority_queue<Pair,vector<Pair>,myComp> pq;
   for(int i = 0 ; i < lists.size();i++){
       pq.push({0,lists[i][0],i});
   }
   
   while(!pq.empty()){
       Pair rem = pq.top();
       pq.pop();
       rv.push_back(rem.val);
       rem.index++;

       if(rem.index < lists[rem.listnumber].size()){
           pq.push({rem.index,lists[rem.listnumber][rem.index],rem.listnumber});
       }
   }
 


  return rv;
}

int main() {
  int k;
  cin >> k;
  vector<vector<int>>lists;
  for (int i = 0; i < k; i++) {
    vector<int>list;

    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      int data;
      cin >> data;
      list.push_back(data);
    }

    lists.push_back(list);
  }

  vector<int> mlist = mergeKSortedLists(lists);
  for (int val : mlist) {
    cout << val << " ";
  }
  cout <<endl;
  return 0;
}