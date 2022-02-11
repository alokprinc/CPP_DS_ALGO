#include<iostream>
#include<stack>
using namespace std;

void  insertAtBottom(stack<int> &st, int element){
    if (st.empty())
    {
        st.push(element);
    }
    
int topelement = st.top();
st.pop();
insertAtBottom(st,element);
st.push(topelement);
}

 void reverseStack(stack<int> &st){
     if (st.empty())
     {
         return;
     }
     
     int element = st.top();
     st.pop();
     reverseStack(st);
     insertAtBottom(st,element);
 }