#include <bits/stdc++.h>
using namespace std;

int cost(vector<int> arr)
{
    priority_queue<int, vector<int>, greater<int>> maxHeap;

    for (int i = 0; i < arr.size(); i++)
    {
        maxHeap.push(arr[i]);
    }
    int a = maxHeap.top();
    maxHeap.pop();
    int b = maxHeap.top();
    int cost = a + b;
    int tc = cost;
    maxHeap.pop();
    for (int i = 0; i < arr.size() - 2; i++)
    {
        int c = maxHeap.top();
        maxHeap.pop();
        cost = cost + c;
        tc = tc + cost;
    }
    return tc;
}

int main()
{
    vector<int> arr = {2, 5, 4, 8, 6, 9};
    cout<<cost(arr)<<" ";
}