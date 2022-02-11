#include <bits/stdc++.h>
using namespace std;
void sol(string str, unordered_set<string> mp, string ans)
{

    if (str.length() == 0 )
    {
            cout << ans << endl;
            return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        string s = str.substr(0, i + 1);
        string rem = str.substr(i + 1);
        if (mp.find(s) != mp.end())
        {
           // mp.erase(s);
            sol(rem, mp, ans + s + " ");
           // mp.insert(s);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    unordered_set<string> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp.insert(s);
    }
    string str;
    cin >> str;
    // cout<<str;
    sol(str, mp, "");
}