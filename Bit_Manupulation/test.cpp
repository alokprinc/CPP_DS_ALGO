#include<bits/stdc++.h>
using namespace std;
void solution(vector<int> &v1)
{
    int xorr=0;
    for(int &ele:v1) xorr^=ele;
    for(int i=1;i<=v1.size();++i) xorr^=i;
    int mask=xorr&(-xorr);
    int ans1=0,ans2=0;
    for(int &ele:v1){
        if((ele&mask)==0) ans1^=ele;
        else ans2^=ele;
    }
    for(int i=1;i<=v1.size();++i)
    {
        if((i&mask)==0) ans1^=i;
        else ans2^=i;
    }
    for(int &ele:v1)
    {
        if(ele==ans1)
        {
            cout<<"Missing Number -> "<<ans2<<"\n";
            cout<<"Repeating Number -> "<<ans1<<"\n";
            break;
        }
        else if(ele==ans2)
        {
            cout<<"Missing Number -> "<<ans1<<"\n";
            cout<<"Repeating Number -> "<<ans2<<"\n";
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