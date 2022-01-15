#include <bits/stdc++.h>
using namespace std;
void display(vector<int>a){
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}
vector<int> solve(vector<int>arr)
{
    stack<int> st;
    st.push(arr[arr.size()-1]);
    vector<int> ans(arr.size());
    ans[arr.size()-1] = arr.at(arr.size()-1);

  for(int i = arr.size()-1 ; i >= 0 ; i--){
      while (st.size()>0 and arr[i] >= st.top())
      {
        st.pop();
      }

      if(st.empty()){
          ans[i] = -1;
      }else{
          ans[i] = st.top();
      }

      st.push(arr[i]);
      
  }

  return ans;
}
int main(int argc, char **argv)
{  
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>nge(n,0);
    nge=solve(arr);
    display(nge);
   return 0;
}