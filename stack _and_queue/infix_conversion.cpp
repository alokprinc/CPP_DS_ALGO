#include<bits/stdc++.h>
using namespace std;

int precedence(char ch ){
    if(ch == '+' || ch == '-'){
        return 1;
    }else if(ch == '*' or ch == '/'){
        return 2;
    }else if(ch == '^'){
        return 3;
    }
    else{
        return 0;
    }
}
bool isNum(char ch){
    if(
        (ch >= '0' and ch <= '9') or
        (ch >= 'a' and ch <= 'z') or
        (ch >= 'A' and ch <= 'Z')
        ){
        return true;
    }
    return false;
}
bool isOperator(char ch){
    if(ch == '+' or ch == '-' or ch == '/' or ch == '*'){
        return true;
    }
    return false;
}
void infix_conversion(string str){
    stack<string> prefix;
    stack<string> postfix;
    stack<char> opr;

    for(int i = 0; i < str.length(); i++){
        char ch = str.at(i);

        if(ch == '('){
            opr.push(ch);
        }
        
        else if((ch >= '0' and ch <= '9') or
        (ch >= 'a' and ch <= 'z') or
        (ch >= 'A' and ch <= 'Z'))
        {
            string s = string(1, ch);
            prefix.push(s);
            postfix.push(s);
        }
        else if(ch == ')')
        {
            while(opr.size() > 0 and opr.top() != '(')
            {
                char o = opr.top();
                opr.pop();
                string op = string(1,o); 

                string postv2 = postfix.top();
                postfix.pop();
                string postv1 = postfix.top();
                postfix.pop();
                string postv = postv1 + postv2 + op;

                string prev2 = prefix.top();
                prefix.pop();
                string prev1 = prefix.top();
                prefix.pop();
                string prev = op + prev1 + prev2;
                
                prefix.push(prev);
                postfix.push(postv);   
            }
            opr.pop();
        }
        else if(isOperator(ch))
        {
            while(opr.size() > 0 and
             opr.top() != '(' and
             precedence(ch) <= precedence(opr.top()))
             {
                char o = opr.top();
                opr.pop();
                string op = string(1,o); 

                string postv2 = postfix.top();
                postfix.pop();
                string postv1 = postfix.top();
                postfix.pop();
                string postv = postv1 + postv2 + op;
                postfix.push(postv);

                string prev2 = prefix.top();
                prefix.pop();
                string prev1 = prefix.top();
                prefix.pop();
                string prev = op + prev1 + prev2;
                prefix.push(prev);
                   
            }
            
            opr.push(ch);
        }
      
    }
     while(opr.size() > 0)
                {
                char o = opr.top();
                opr.pop();
                string op = string(1,o); 

                string postv2 = postfix.top();
                postfix.pop();
                string postv1 = postfix.top();
                postfix.pop();
                string postv = postv1 + postv2 + op;

                string prev2 = prefix.top();
                prefix.pop();
                string prev1 = prefix.top();
                prefix.pop();
                string prev = op + prev1 + prev2;
                
                prefix.push(prev);
                postfix.push(postv);     
                }
   string post = postfix.top();
    string pre = prefix.top();
    
    cout << post << endl;
    cout << pre << endl;
}
int main(){
    string str;
  getline(cin, str);
    
    infix_conversion(str);
}