#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int c = 0;
    while(n!=0){
        n = n - (n&(-n));
        c++;
    }
    cout<<c;
    return 0;
}