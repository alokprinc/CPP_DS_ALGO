#include <bits/stdc++.h>
using namespace std;
int Operation(int v1, int v2, char op)
{
    if (op == '+')
    {
        return v1 + v2;
    }
    else if (op == '-')
    {
        return v1 - v2;
    }
    else if (op == '*')
    {
        return v1 * v2;
    }
    else if (op == '/')
    {
        return v1 / v2;
    }
}
int main()
{
    string exp;
    cin >> exp;

    stack<string> infix;
    stack<string> postfix;
    stack<int> evaluation;

    for (int i = exp.length() - 1; i >= 0; i--)
    {
        char ch = exp.at(i);
        if (ch >= '0' and ch <= '9')
        {   
            string s = string(1,ch);
            evaluation.push(ch - '0');
            postfix.push(s);
            infix.push(s);
        }
        else
        {
            int v1 = evaluation.top();
            evaluation.pop();
            int v2 = evaluation.top();
            evaluation.pop();

            evaluation.push(Operation(v1,v2,ch));

            string postv1 = postfix.top();
            postfix.pop();
            string postv2 = postfix.top();
            postfix.pop();
            string s = string(1,ch);
            postfix.push(postv1 + postv2 + s);

            string inv1 = infix.top();
            infix.pop();
            string inv2 = infix.top();
            infix.pop();
            string s2 = string(1,ch);
            string bo = string(1,'(');
            string bc = string(1,')');
            infix.push(bo + inv1 + s2 + inv2 + bc);


        }
    }
    cout<<evaluation.top()<<endl;
    cout<<infix.top()<<endl;
    cout<<postfix.top()<<endl;

    return 0;
}