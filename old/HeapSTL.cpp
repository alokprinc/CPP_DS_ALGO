#include<bits/stdc++.h>

using namespace std;
// push = O(log(n))
// pop = O(log(n))
// top = O(1)
// size = O(1)
int  main(){

// vector<int> arr ={ 4, 6, 3, 2, 9 };
// priority_queue<int,vector<int> >pq;
// for (int i = 0; i < 5; i++)
// {
//     pq.push(arr[i]);
// }
// for (int i = 0; i < 5; i++)
// {
//     cout<<pq.top()<<" ";
//     pq.pop();
// }

vector<int> arr ={ 4, 6, 3, 2, 9 };

make_heap(arr.begin(),arr.end());

for (int &i: arr)
{
    cout<<i<<" ";
}



}