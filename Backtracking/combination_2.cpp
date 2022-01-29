#include<bits/stdc++.h>
using namespace std;
void combination(vector<int> box,int ci,int ti,int cb,int tb,int lastVal){
    if(ci > ti){
        for(auto a: box){
            if(a){
                cout<<"i";
            }else{
                cout<<"-";
            }
          
        }  cout<<endl;
        return;
    }
    for(int i = lastVal+1; i < tb;i++){
        if(box[i]==0){
            box[i] = 1;
            combination(box,ci+1,ti,cb+1,tb,i);
            box[i] = 0;
        }
    }
}
int main(){
    int box,item;
    cin>>box>>item;
vector<int> boxes(box,0);

    combination(boxes,1,item,1,box,-1);
}