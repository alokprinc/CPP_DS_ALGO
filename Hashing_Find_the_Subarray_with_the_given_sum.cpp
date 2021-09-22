#include<bits/stdc++.h>
using namespace std;

void findSubarray(vector<int> arr,int sum){
    int currSum =0;
    int start = 0;
    int end = -1;
    int n = arr.size();
     map<int,int> m;
     map<int,int> :: iterator itr;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];

        if(currSum == sum){
            start = 0;
            end = i;
            return;
        }
        // bool flag=false;
        // for (itr = m.begin(); itr != m.end(); ++itr)
        // {
        //     if(itr->second == currSum-sum){
        //         flag = true;
               
        //     }
        // }
        
        if(m.find(currSum - sum) != m.end()){
            start = m[currSum - sum ]+1;
            end = i;
            return;
        }
       m[currSum] = i;
    }
    if(end == -1){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"Found b/w "<< start << "-> "<< end<<endl;
    }
}


int main(){
   vector<int> arr = {10, 2, -2, -20, 10};
    int sum = -10;

    findSubarray(arr,sum);


}