#include<iostream>
using namespace std;

int main(){

int n=5;

for (int i = 1; i <= n; i++)
{ for (int j = n-i; j>=0; j--){
     cout<<"*";
     } cout<<endl;
    }

int x = 5;
for (int i = 1; i <= x ; i++){
    for (int j = 1; j <= x ; j++)
 {
     if(j<=x-i){
         cout<<" ";
     }
         else cout<<"*";
 }
 cout << endl;
 }

 int q= 5;

 for (int i = 1; i <= q; i++){
     for (int j = 1; j <= i; j++)
     {
         
             cout<<i;
         } cout<< endl;
     }

     // floyds Triangle
int count = 1;
     for (int i = 1; i <= q; i++){
     for (int j = 1; j <= i; j++)
     {
         
             cout<<count;
             count++;
         } cout<< endl;
     }

     // Butterfly Pattern;
int z=15;
q=z;
        for(int i=1; i<=q; i++){
            for(int j=1;j<= i; j++){
                cout<<"*";
            }
            int space = 2*q - 2*i;
            for (int j = 0; j <= space; j++)
            {
                cout<<" ";
            }
             for(int j=1;j<= i; j++){
                cout<<"*";
            }
            cout<<endl;
            }
            
        for(int i=q; i>=1; i--){
            for(int j=1;j<= i; j++){
                cout<<"*";
            }
            int space = 2*q - 2*i;
            for (int j = 0; j <= space; j++)
            {
                cout<<" ";
            }
             for(int j=1;j<= i; j++){
                cout<<"*";
            }
            cout<<endl;
            }


     
 }

