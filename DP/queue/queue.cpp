#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<pair,vector<pair<int,int>>,greater<int> > pq;
    int arr[] = {6,3,8,4,6,2,5,6,4,8};
    for(int i = 0; i < 10;i++)
    pq.push({i,arr[i]});

}