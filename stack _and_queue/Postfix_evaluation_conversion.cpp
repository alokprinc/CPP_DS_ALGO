#include <bits/stdc++.h>
using namespace std;

bool isNum(char ch)
{
    if (ch >= '0' and ch <= '9')
    {
        return true;
    }
    return false;
}

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
    getline(cin, exp);

    stack<string> infix;
    stack<string> prefix;
    stack<int> evaluation;

    for (auto ch : exp)
    {
        if (isNum(ch))
        {   
            string s = string(1,ch);
            evaluation.push(ch - '0');
            infix.push(s);
            prefix.push(s);
        }
        else
        {   

            int v2 = evaluation.top();
            evaluation.pop();
            int v1 = evaluation.top();
            evaluation.pop();

            evaluation.push(Operation(v1, v2, ch));

            string prev2 = prefix.top();
            prefix.pop();
            string prev1 = prefix.top();
            prefix.pop();
            string s = string(1,ch);
            prefix.push(s + prev1 + prev2);

            string inv2 = infix.top();
            infix.pop();
            string inv1 = infix.top();
            infix.pop();
            string s2 = string(1,ch);
            string bo = string(1,'(');
            string bc = string(1,')');
            infix.push(bo + inv1 + s2 + inv2 + bc);

        }
    }
    cout<<evaluation.top()<<endl;
    cout<<infix.top()<<endl;
    cout<<prefix.top()<<endl;


    return 0;
}