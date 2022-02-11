#include <iostream>
using namespace std;

int friendsArrangement(int n){
if(n==0 || n==1 || n == 2 )
        return n;

        return friendsArrangement(n-1)+friendsArrangement(n-2)*(n-1);
}



int main(){
cout<<friendsArrangement(4);
}