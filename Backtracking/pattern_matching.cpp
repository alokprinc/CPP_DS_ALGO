#include <bits/stdc++.h>
using namespace std;
void sol(string str, string pattern, unordered_map<char, string> mp, int idx)
{
    if (idx == pattern.length())
    {
        if (str.length() == 0)
        {
            for(int i = 0 ; i < pattern.length();i++){
                if(mp.find(pattern[i]) != mp.end()){
                    cout<<pattern[i]<<" -> "<<mp[pattern[i]]<<", ";
                    mp.erase(pattern[i]);
                }
            }
            cout<<". "<<endl;
        }
    }
    char ch = pattern[idx];
    if (mp.find(ch) != mp.end())
    {
        string cstr = mp[ch];
        if (str.substr(0, cstr.length()) == cstr)
        {
            sol(str.substr(cstr.length()), pattern, mp, idx + 1);
        }
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            string lft = str.substr(0, i + 1);
            string rht = str.substr(i + 1);

            mp.insert({ch, lft});
            sol(rht, pattern, mp, idx + 1);
            mp.erase(ch);
        }
    }
}
int main()
{
    string str;
    string pattern;

    getline(cin, str);
    getline(cin, pattern);

    unordered_map<char, string> mp;

    sol(str, pattern, mp, 0);
}