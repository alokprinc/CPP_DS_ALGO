#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> most_freq_element(vector<int> arr, int k)
{
    map<int, int> m;
    int n = arr.size();
    vector<pair<int,int>> ans;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    map<int, int>::iterator it;
    int i = 0;
    for (it = m.begin(); it != m.end(); ++it)
    {
        pair<int, int> p;
        if (i < k -1)
        {
            // cout << it->first << " -> " << it->second << endl;
            p.first = it->first;
            p.second = it->second;
            ans.push_back(p) ;
            
        }
        i++;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 3, 4, 5};
    int k = 3;

    vector<pair<int, int>> v = most_freq_element(arr, k);
    
    for (int i = 0; i < v.size(); i++)
    {
        pair<int,int> p = v[i];
        cout<<p.first<<"->"<<p.second<<endl;
    }
    
}