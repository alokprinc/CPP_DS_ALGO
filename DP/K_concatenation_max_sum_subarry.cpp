#include <bits/stdc++.h>
using namespace std;
int kadane(vector<int> arr, int n)
{
    int cs = arr[0];
    int os = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (cs >= 0)
        {
            cs += arr[i];
        }
        else
        {
            cs = arr[i];
        }
        os = max(cs, os);
    }
    return os;
}
long sum(vector<int> arr, int n)
{
    long sm = 0;
    for (int i = 0; i < n; i++)
    {
        sm += arr[i];
    }
    return sm;
}
int sol(vector<int> arr, int n, int k)
{
    vector<int> arr2(n + n, 0);
    long sm = sum(arr, n);
    if (k == 1)
    {
        
        return kadane(arr, n);
    }
    else if (sm <= 0)
    {

        for (int i = 0; i < n; i++)
        {
            arr2[i] = arr[i];
        }
        for (int i = n; i < n + n; i++)
        {
            arr2[i] = arr[i - n];
        }
        return kadane(arr2, n+n);
    }
    else if (sm > 0)
    {
        
        return k*sm;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> arr2(n+n);
    for (int i = 0; i < n; i++)
        {
            arr2[i] = arr[i];
        }
        for (int i = n; i < n + n; i++)
        {
            arr2[i] = arr[i - n];
        }
       // cout<<kadane(arr2,n+n);
    int k;
    cin >> k;
    cout<<sol(arr, n, k);
}