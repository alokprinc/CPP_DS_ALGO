#include <iostream>
using namespace std;

int fibonachi(int n){
if(n == 0) return 0;
else if (n == 1) return 1 ;

    return fibonachi(n-1) + fibonachi(n-2);
}

int factorial(int n){
if(n == 0) return 1;

return n*factorial(n-1);
}

int main(){
int n;
cin>>n;
for (int i = 0; i <= n; i++)
{
    cout<<fibonachi(i)<< " ";
}



}