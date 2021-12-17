#include <iostream>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' or s[i] == '[' or s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                st.pop();
                break;
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (st.top() == '[')
            {
                st.pop();
                break;
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
                break;
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    string s ;
    getline(cin,s);
    if (isValid(s))
    {
        cout << "Valid";
    }
    else
    {
        cout << "Not valid";
    }
}