#include <bits/stdc++.h>
using namespace std;
int main()
{
  string str;
 getline(cin,str);
cout<<str;
  stack<char> st;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ')') {
      if (st.top() == '(') {
        cout << "true" << endl;
        return 0;
      }
      else {
        while (st.top() != '(') {
          st.pop();
        }
        st.pop();
      }

    } else {
        if(str[i] == ' '){
            continue;
        }else{
      st.push(str[i]);
        }
    }
  }
 cout<<"false"<<endl;
  return 0;
}