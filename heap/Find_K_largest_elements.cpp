#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void findKthLargest(vector<int> const& arr, int k) {

  priority_queue<int,vector<int>,greater<int>> pq;
  for(auto a: arr){
      if(k>0){
          pq.push(a);
          k--;
      }else{
          if(pq.top() < a){
              pq.pop();
              pq.push(a);
          }
      }
  }

    while(pq.size() > 0){
        cout<<pq.top()<<endl;
        pq.pop();
    }
  
    return;
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
  int k;
  cin >> k;
 
     findKthLargest(arr, k);

  return 0;

}