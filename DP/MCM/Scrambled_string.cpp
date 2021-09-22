#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;

bool Scrambled_String(string a, string b)
{
    int n = a.length();
    if (a.compare(b) == 0)
    {
        return true;
    }
    if (a.length() <= 1)
    {
        return false;
    }
    string temp = a + " "+b;
    cout<<temp;
    cout<<endl;
    if(mp.find(temp) != mp.end()){
        return mp[temp];
    }
    // if(a.length() != b.length()){
    //     return false;
    // }
    // if(a.empty() & b.empty()){
    //     return true;
    // }

    bool flag = false;
    for (int i = 1; i < n ; i++)
    {
        if (  Scrambled_String(a.substr(0, i), b.substr(n - i, i)) == true &&  Scrambled_String(a.substr(i, n - i), b.substr(0, n - i)) == true
             
             ||

            Scrambled_String(a.substr(0, i), b.substr(0, i)) == true &&  Scrambled_String(a.substr(i, n - i), b.substr(i, n - i)  ) == true)
        {
            flag = true;
            break;
        }
    }
    return mp[temp] = flag;
}

int main()
{   
    string a = "great";
    string b = "eargt";
    
    cout << Scrambled_String(a, b);
}