#include <bits/stdc++.h>
using namespace std;
void handlechar(stack<char> st,char ch){
    if(st.size() == 0){
               cout<<"true";
               return;
           }else if(st.top() != '('){
               cout<<"false";
           }else{
               st.pop();
           }
}
int main()
{ 
    string str;
    getline(cin,str);
    stack<char> st;
    bool ans = false;
    for(auto ch : str){
        if(ch == ')'){
            char chr = '(';
           handlechar(st,chr);
        }else if(ch == ']'){
            char chr = '[';
           handlechar(st,chr);
        }else if(ch == '}'){
            char chr = '(';
           handlechar(st,chr);
        }else{
            if(ch == '(' or ch == '[' or ch == '{')
            st.push(ch);
        }
        // if(st.size() == 0){
        //     ans = true;
        // }
        // else{
        //     ans = false;
        // }
    }
    if(ans == true){
        cout<<"true";
    }else{
        cout<<"false";
    }
   return 0;
}