#include<bits/stdc++.h>
using namespace std;
int power2(int n){
    int i = 1;

    while(i*2 <= n){
        i = i*2;
    }
    return i;
}
int main(){
    int n;
    cin>>n;

    int power = power2(n);
    int l = n-power;

    cout<<2*l+1;

}