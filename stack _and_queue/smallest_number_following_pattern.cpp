#include<iostream>
#include <string>
#include <stack>
using namespace std;



int main() {
  string str;
  cin >> str;

  // write your code here
  stack<int> st;
  int n = 1;

  for (int i = 0 ; i < str.length(); i++) {
    char ch = str[i];
    if (ch == 'd') {
      st.push(n);
      n++;
    } else {
      st.push(n);
      n++;
      while (!st.empty()) {
        cout << st.top();
        st.pop();
      }
    }
  }
  st.push(n);
  while (!st.empty()) {
    cout << st.top();
    st.pop();
  }

}