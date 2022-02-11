#include <bits/stdc++.h>
using namespace std;
#define Vi vector<int>
priority_queue<int, vector<int>> maxH;
priority_queue<int, vector<int>, greater<int>> minH;

void insert(int x)
{
     if (maxH.size() == minH.size())
     {
        if (maxH.empty())
        {
            maxH.push(x);
            return;
        }
        if (maxH.top() <= x)
        {
            minH.push(x);
        }
        if (minH.top() >= x)
        {
            maxH.push(x);
        }
   }
    else{
        if (maxH.size() > minH.size())
        {
            if (maxH.top() <= x)
            {
                minH.push(x);
            }
            else
            {
                int temp = maxH.top();
                maxH.pop();
                maxH.push(x);
                minH.push(temp);
            }
        }
        else
        {
            if (minH.top() >= x)
            {
                maxH.push(x);
            }
            else
            {

                int temp = minH.top();
                minH.pop();
                maxH.push(temp);
                minH.push(x);
            }
        }

   }
}

double findMedian()
{
    if (maxH.size() == minH.size())
    {
        return (maxH.top() + minH.top()) / 2.0;
    }
    else if (maxH.size() > minH.size())
    {
        return maxH.top();
    }
    else
    {
       return minH.top();
    }
}

int main()
{
    Vi arr = {3, 1, 5, 4};

    for (int i = 0; i < arr.size(); i++)
    {
        insert(arr[i]);
        cout<<"Adding : "<<arr[i]<<"median is -> "<<findMedian()<<endl;
    }
    

   
}