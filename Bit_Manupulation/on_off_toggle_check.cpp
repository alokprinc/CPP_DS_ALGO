#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,k,m;
    cin>>n>>i>>j>>k>>m;

    int onMask = (1 << i);
    int offMask = ~(1 << j);
    int toggleMask = (1 << k);
    int checkMask = (1 << m);

    cout<<(n | onMask)<<endl;
    cout<<(n & offMask)<<endl;
    cout<<(n ^ toggleMask)<<endl;
    cout<<(((n & checkMask)==0)?"false":"true")<<endl;
}