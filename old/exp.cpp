#include<bits/stdc++.h>
using namespace std;
 map<int,int> :: iterator it;
int main(){
    int arr[] = {10,20,30,40,40,40,70,80,90};
    map<int,int> map;
   

for(int i = 0 ; i < 9; i ++){
    map[arr[i]] = i;
}
 
// for (it = map.begin(); it != map.end(); it++)
//     {
//         cout<<it->first<<" -> "<<it->second<<endl;;
//     }
//    for (int i = 0; i < 9; i++)
//    {
//        cout<<map.count(100)<<endl;
//    }


   
}