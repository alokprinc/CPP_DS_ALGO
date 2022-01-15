#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;
void  next_greater_element(vector<int> arr,int n){
    stack<int> st;
    vector<int> nge;
    nge[n-1] = n;
    st.push(n-1);
    for(int i = n-2; i >= 0; i++){
        while(st.size()>0 and arr[i] >= arr[st.top()]){
            st.pop();
        }
        if(st.size() == 0){
            nge[i] = n;
        }else{
            nge[i] = st.top();
        }
        st.push(i);
    }
    for(auto i:nge){
        cout<<i<<" ";
    }
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int k;
  cin >> k;

  next_greater_element(arr,n);

  return 0;
}