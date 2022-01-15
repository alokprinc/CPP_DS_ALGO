#include <bits/stdc++.h>
using namespace std;

void largest_Histogram(vector<int> arr,int n){
    
    vector<int> rb(n,0);
    stack<int> st;
    st.push(n-1);
    rb[n-1] = n;

    for(int i = n -2; i >=0 ; i--){
        while(st.size() > 0 and arr[i] <= arr[st.top()]){
            st.pop();
        }

        if(st.size() == 0){
            rb[i] = n;
        }else{
            rb[i] = st.top();
        }

        st.push(i);
    }
vector<int> lb(n,0);
    stack<int> st2;
    st.push(0);
    lb[0] = -1;

    for(int i = 1; i < n ; i++){
        while(st2.size() > 0 and arr[i] <= arr[st2.top()]){
            st2.pop();
        }

        if(st2.size() == 0){
            lb[i] = -1;
        }else{
            lb[i] = st2.top();
        }

        st2.push(i);
    }
    
    int maxArea = 0;
    for(int i = 0; i < n;i++){
        int width = rb[i] - lb[i] -1;
        int area = width*arr[i];
        if(area > maxArea){
            maxArea = area;
            
        }
    }
    cout<<maxArea;
}

int main(int argc, char** argv)
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  largest_Histogram(arr,n);
  return 0;
}