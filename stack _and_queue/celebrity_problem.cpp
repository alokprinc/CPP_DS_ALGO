#include<bits/stdc++.h>
using namespace std;
// void findCelebrity(vector<vector<int>> arr,int n,stack<int> &personNum){
//    while(personNum.size() >= 2){
//        int p1 = personNum.top();
//        personNum.pop();
//        int p2 = personNum.top();
//        personNum.pop();

//        if(arr[p1][p2] == 1){
//            // p1 is not celeb
//            personNum.push(p2);
//        }else{
//            // p2 is not a celeb
//            personNum.push(p1);
//        }
//    }
//    int candidate = personNum.top();
//    personNum.pop();
//     cout<<candidate;
//    for(int i = 0; i < n; i++){
//        if(i != candidate){
//            if(arr[i][candidate] == 1 or arr[candidate][i] == 1){
//                cout<<"none"<<endl;
//                return;
//            }
//        }
//    }
//    cout<<candidate<<endl;
// }
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr;
    stack<int> personNum;
    for(int i = 0; i < n;i++){
        for(int j = 0 ; j < n;j++){
        
        int a;
        cin>>a;
        arr[i][j] = a;
        cout<<arr[i][j];
        }
        personNum.push(i);
        cout<<i;
    }

    //findCelebrity(arr,n,personNum);
    return 0;
}