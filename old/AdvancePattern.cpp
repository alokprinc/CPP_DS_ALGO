#include <iostream>
using namespace std;

int main()
{
//     // 12345
//     // 1234
//     // 123  // Pattern1
//     // 12
//     // 1
 //    int n = 5;
//     int count = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n - i + 1; j++)
//         {
//             cout << count;
//             count++;
//         }
//         cout << endl;
//         count = 1;
//     }

//     // Pattern 2

//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             if ((j + i) % 2 == 0)
//             {
//                 cout << "1";
//             }
//             else
//                 cout << "0";
//         }
//         cout << endl;
//         /* code */
//     }

//     // Pattern 3
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= n - i; j++)
//         {
//             cout << " ";
//         }
//         for (int j = 0; j <= n; j++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }

//     // Pattern 4
// count=1;
//     for (int i = 0; i <= n; i++)
//     { for (int j = 0; j <= n-i; j++)
//     {
//         cout<<" ";
//     } for (int j = 0; j <= i; j++)
//     {
//         cout<<j<<" ";
      
//     } cout<<endl;
//     }
    

    // Pattern 5

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n-i; j++)
    //     {
    //         cout<<" ";
    //     }
    //     for (int j = i; j >=  1 ; j--)
    //     {
    //         cout<<j;
    //     }
    //     for (int j = 2; j <= i; j++)
    //     {
    //         cout<<j;
    //     }
        
        
        
     //cout<<endl;
  //  }

  // Pattern 6

//   for (int i = 1; i <= n; i++)
//   {
//       for (int j = 1; j <= n-i; j++)
//       {
//           cout<<" ";
//       }
//       for (int j = 1; j <= 2*i-1; j++)
//       {
//           cout<<"*";
//       }
//       cout<<endl;
//   }
//   for (int i = n; i >= 1; i--)
//   {
//       for (int j = 1; j <= n-i; j++)
//       {
//           cout<<" ";
//       }
//       for (int j = 1; j <= 2*i-1; j++)
//       {
//           cout<<"*";
//       }
//       cout<<endl;
//   }
  
      //Pattern 7

//      int k=9;
//      int n = 3;
   
// for (int i = 1; i <= n; i++)
// {
//     for (int j = 1; j <= k; j++)
//     {
//         if((i+j)%4 == 0 || (i == 2 && j % 4 == 0)) cout<<"*";

//         else cout<<" ";
//     } cout << endl;
    
// }
 
 //Pattern 8
 int k=5;   // increasing value of k will move pattern toward right
     int n = 3;
   
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= k; j++)
    {
        if((i+j)%4 == 0 || (i == 2 && j % 4 == 0)) cout<<"*";

        else cout<<" ";
    } cout << endl;
    
}
for (int i = n; i >= 1; i--)
{
    for (int j = 1; j <= k; j++)
    {
        if((i+j)%4 == 0 || (i == 2 && j % 4 == 0)) cout<<"*";

        else cout<<" ";
    } cout << endl;
    
}
    
    
}