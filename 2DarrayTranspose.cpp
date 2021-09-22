#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n ;

    int arr[n][n],arrT[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
 
 for (int i = 0; i < n; i++)
 {
     for (int j = 0; j < n; j++)
     {
         if(i == j){
             arrT[j][j] = arr[i][i];
         } else {
             arrT[j][i] = arr[i][j];
         }
     }
     
 }
 for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arrT[i][j]<<" ";
        }
        cout<<endl;
    }
 

}
