#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
   int c=n;
   int r=0;
    while(n != 0){
        c = c + (n/3);
        n=n/3 ;
        if(n%3 > 1){
         r = r+ n%3;
        }

        if(n/3 == 0){
            r = r + n;
        }
    }
    cout<< c + r/3;
}