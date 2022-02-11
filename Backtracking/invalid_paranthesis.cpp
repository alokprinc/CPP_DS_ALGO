#include <bits/stdc++.h>
using namespace std;
int minRemove(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        
        if (ch == '(')
        {
            st.push(ch);
            
        }
        else if (ch == ')')
        {
            if(st.size() == 0){
                st.push(ch);
            }
            else if (st.top() == '(')
            {
                st.pop();
            }
            else if (st.top() == ')')
            {
                st.push(ch);
            }
        }
    }
    // while(st.size()){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }
    return st.size();
}
void sol(string str,int idx,int ts,unordered_set<string> &mp)
{   
    if(idx == ts){
        int x = minRemove(str);
        if(x == 0){
            if(mp.find(str)==mp.end()){
                cout<<str<<endl;
                mp.insert(str);
            }
        }
        return;
    }
    for(int i = 0 ; i < str.length(); i++){
        string lft = str.substr(0,i);
        string rht = str.substr(i+1);
        sol(lft+rht,idx+1,ts,mp);
    }

}
int main()
{
    string str;
    getline(cin, str);
    
    int a = minRemove(str);
    unordered_set<string> mp;
     sol(str,0,a,mp);
}