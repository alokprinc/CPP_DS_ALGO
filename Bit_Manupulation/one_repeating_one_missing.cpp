#include<bits/stdc++.h>
using namespace std;
void solution(vector<int> &v1)
{
    int xorr = 0;
    for(auto a:v1){
        xorr ^= a;
    }

    for(int i = 1 ; i <= v1.size();i++){
        xorr ^= i;
    }

    int rmsb = (xorr & (-xorr));
    int onxor = 0;
    int offxor = 0;
    for(auto a:v1){
        if((a & rmsb) == 0){
            offxor ^= a;
        }else{
            onxor ^= a;
        }
    }
     for(int i = 1 ; i <= v1.size();i++ ){
        if((i & rmsb) == 0){
            offxor ^= i;
        }else{
            onxor ^= i;
        }
    }
    for(auto a:v1){
        if(a == onxor){
            cout<<"Missing Number -> "<<offxor<<endl;
            cout<<"Repeating Number -> "<<onxor;
            break;
        }else if(a == offxor){
            cout<<"Missing Number -> "<<onxor<<endl;
            cout<<"Repeating Number -> "<<offxor;
            break;
        }
    }
}
int main()
{
    int n;cin>>n;
    vector<int> v1(n);
    for(int i=0;i<n;++i) cin>>v1[i];
    solution(v1);
    return 0;
}