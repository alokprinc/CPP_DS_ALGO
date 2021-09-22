#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
int egg_droping(int e, int f)
{

    if (e == 1)
    {
        return f;
    }
    if (f == 0 || f == 1)
    {
        return f;
    }
    string temp = to_string(e) + " " + to_string(f);
    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }
   
    int ans = INT_MAX;
    for (int k = 1; k < f; k++)
    {
        int low = 0;
        if (mp.find(temp) != mp.end())
        {
            low = egg_droping(e - 1, k - 1);
        }
        else
        {
            low = mp[temp];
        }
        int hi = 0;
        if (mp.find(temp) != mp.end())
        {
            hi = egg_droping(e, f - k);
        }
        else
        {
            hi = mp[temp];
        }
        
        int temp = 1 + max(low, hi);
        ans = min(temp, ans);
         
    }
    return mp[temp] = ans;
}

int main()
{
    int e = 3;
    int f = 5;
    cout << egg_droping(e, f);
}