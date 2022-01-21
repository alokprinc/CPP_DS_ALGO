#include<bits/stdc++.h>
using namespace std;
void findCeleb(stack<int> st,vector<vector<int>> arr,int n){
    while(st.size() > 1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if(arr[a][b] == 1){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }
    
    int a = st.top();
    //cout<<a;
    st.pop();
    
    for(int i = 0; i < n;i++){
        if(i != a){
        if(arr[a][i] == 0 or arr[i][a] == 1){
            cout<<"none"<<endl;
            return;
        }
        }
    }
    cout<<a<<endl;
    return ;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    stack<int> personNum;
    for(int i = 0; i < n;i++){
        for(int j = 0 ; j < n;j++){
        
        int a;
        cin>>a;
        arr[i][j] = a;
        }
        personNum.push(i);
        
    }
   // cout<<arr[0].size();
    findCeleb(personNum,arr,n);
    return 0;
}