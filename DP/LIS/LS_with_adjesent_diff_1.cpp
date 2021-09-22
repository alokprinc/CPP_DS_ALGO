#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int longestSubsequence(int n, int A[])
{
    //    vector<int> t(n,1);
    //    t[0] = 1;
    //    for(int i = 0 ; i <n ; i++){
    //        for(int j = 0 ; j < i; j++){
    //            if(abs(A[i] - A[j] == 1)){
    //                t[i] = max(t[i],t[j] + 1);
    //            }
    //        }
    //    }
    //    int ma  = 0;
    //    for(int i = 0; i < n; i++){
    //        ma = max(ma,t[i]);
    //    }
    //    return ma;

    unordered_map<int, int> m;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 0;
        if (m[A[i] - 1])
        {
            l = m[A[i] - 1];
        }
        if (m[A[i] + 1] and m[A[i] + 1] > l)
        {
            l = m[A[i] + 1];
        }

        m[A[i]] = l + 1;

        mx = max(mx, m[A[i]]);
    }
    return mx;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << longestSubsequence(n, a);
}