#include <iostream>
#include<climits>
using namespace std;

// //  BRUTE FORCE //// O(N3)
        
// int main()
// {
//     int n;
//     cin >> n;
// int sum = 0;
// int mx = INT_MIN;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             sum = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 sum = sum + arr[k];
               
//             }
//              mx = max(mx,sum);
             
//         }
        
//     } 
//   cout << mx << " ";
//             cout<<endl;
// }

// // Optimised approach //  O(N2)

// int main()
// {
//     int n;
//     cin >> n;
// int sum = 0;
// int mx = INT_MIN;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//  for (int i = 0; i < n; i++)
//  {  sum = 0;
//      for (int j = i; j < n; j++)
//      {
//          sum = sum + arr[j];

//      } cout << sum<< " ";
//      mx = max(sum,mx);
//  } 
//   cout <<endl<< mx<< " ";
// }

// Kadane's Algorithm //

int main()
{
    int n;
    cin >> n;
int currentSum = 0;
int mx = INT_MIN;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

 for (int i = 0; i < n; i++)
 { 
     currentSum = currentSum + arr[i];
if(currentSum < 0){
    currentSum = 0;
}
mx = max(mx,currentSum);
 } 
  cout <<endl<< mx<< " ";
}



