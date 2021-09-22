#include <bits/stdc++.h>
using namespace std;
deque<int> converter(int x)
{
    deque<int> a;
    int res;
    while (x!=0)
    {   
        res = x%10;
        x/=10;
        a.push_front(res);
    }
    return a;
}
vector<int> subSequence(string s, string ans, int k)
{
    vector<int> d;
    if (s.length() == 0)
    {
        if (ans.size() == k)
        {
            // cout << ans << endl;
            stringstream geek(ans);
            int x = 0;
            geek >> x;
           //cout << x << endl;
           d.push_back(x);
         cout<<d.front()<<endl;
       
            return d;
        }
        return d;
    }
    char ch = s[0];
    string remainingString = s.substr(1);

    subSequence(remainingString, ans + ch, k);
    subSequence(remainingString, ans, k);
}

int main()
{
        int k = 3;
  vector<int> dq;
  dq = subSequence("34526", "", k);


// for (int i = 0; i < n; i++)
// {
//     int c = dq.front();
//     dq.pop_front();
    
//     deque<int> ans = converter(c);
    
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout<<ans.front()<<" ";
//         ans.pop_back();
//     }
    
// }


    cout << endl;
}