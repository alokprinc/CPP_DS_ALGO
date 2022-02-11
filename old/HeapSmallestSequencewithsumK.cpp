#include <bits/stdc++.h>
using namespace std;

void minSeq(vector<int> arr, int k)
{
    priority_queue<int, vector<int>> maxH;

    for (int i = 0; i < arr.size(); i++)
    {
        maxH.push(arr[i]);
    }

    int sum=0;
    int count = 0;

   while (!maxH.empty())
    {
        sum += maxH.top();
        maxH.pop();

        count++;

        if(sum >=k){
            break;
        }
    }

    if(sum < k){
        cout<< "-1";
    }else{
        cout<<count;
    }
    
}

int main()
{
    vector<int> arr = {1,1,3,2,8};
    int k = 12;

    minSeq(arr,12);
}