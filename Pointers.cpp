#include<iostream>
using namespace std;

int main(){
    int a= 20;
    int *p = new int();
     *p = 10;

    delete(p);
    cout<<*p<<" ";
 p = new int[4];
 cout<<*p;

 delete[] p;
 p =NULL;
}

// int swap(int *a,int *b){
//     int temp =*a;
//     *a=*b;
//     *b=temp;
// //return *a,*b;
// }
// int main(){
// int a= 10,b=20;
// swap(&a,&b);
// cout<<a<<" "<<b;
// }