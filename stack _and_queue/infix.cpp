#include <bits/stdc++.h>
using namespace std;
int precedence(char optr)
{
    if (optr == '+')
    {
        return 1;
    }
    else if (optr == '-')
    {
        return 1;
    }
    else if (optr == '*')
    {
        return 2;
    }
    else if (optr == '/')
    {
        return 2;
    }
}
int operation(int v2, int v1, char optr)
{
    if (optr == '+')
    {
        return v2 + v1;
    }
    else if (optr == '-')
    {
        return v2 - v1;
    }
    else if (optr == '*')
    {
        return v2 * v1;
    }
    else if (optr == '/')
    {
        return v2 / v1;
    }
}

bool isOperator(char ch)
{
    if (ch == '/' || ch == '*' || ch == '+' || ch == '-')
    {
        return true;
    }
}
void infix(string s)
{
    stack<int> is;
    stack<char> cs;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s.at(i);
        if (ch == '(')
        {
            cs.push(ch);
        }

        else if (isdigit(ch))
        {
            is.push(ch - '0');
        }
        else if (ch == ')')
        {
            while (cs.size() > 0 and cs.top() != '(')
            {
                char optrr = cs.top();
                cs.pop();

                int v2 = is.top();
                is.pop();
                int v1 = is.top();
                is.pop();
                is.push(operation(v2, v1, optrr));
            }
            if (cs.size() > 0)
                cs.pop();
        }
        else if (isOperator(ch))
        {
            while (cs.size() > 0 and cs.top() != '(' and precedence(ch) <= precedence(cs.top()))
            {
                char optrr = cs.top();
                cs.pop();

                int v2 = is.top();
                is.pop();
                int v1 = is.top();
                is.pop();
                is.push(operation(v2, v1, optrr));
            }
            cs.push(ch);
        }
    }
    while (cs.size() > 0)
    {
        char optrr = cs.top();
        cs.pop();

        int v2 = is.top();
        is.pop();
        int v1 = is.top();
        is.pop();
        is.push(operation(v2, v1, optrr));
    }
    cout << is.top();
}
int main()
{
    string s;
    getline(cin, s);

    infix(s);
}