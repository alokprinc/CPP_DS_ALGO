#include <bits/stdc++.h>
using namespace std;

void decToBinary(int n)
{
    stack<int> st;
    while (n!=0)
    {
        int x = n % 2;
        st.push(x);
        n /= 2;
    }
    while(st.size()>0){
        cout<<st.top();
        st.pop();
    }
}

int main()
{

    int n;
    cin >> n;
    char buffer[33];
    int k = (n & (-n));
    decToBinary(k);
}