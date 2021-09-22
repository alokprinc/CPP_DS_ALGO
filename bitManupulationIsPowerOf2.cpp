#include <iostream>
using namespace std;



bool isPowerOf2(int n)
{
    if (n && (n & n - 1) == 0)
        return true;
    else if (n == 1)
        return 0;
    else
        return 0;
}

int countNoOfOnes(int n)
{

    int count = 0;

    while (n)
    {
        n = n & (n - 1);

        count++;
    }

    return count;
}

void subSet(int arr[], int n){
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if( i & ( 1 << j )){
                cout<< arr[j]<<" ";
            }
        } cout<<endl;
        
    }
    
}

int uniqueNumber(int arr[], int n){
        int xorNum= 0;
        for (int i = 0; i < n; i++)
        {
            xorNum = xorNum ^ arr[i];
        }
            return xorNum;        
}


int main()
{
    // cout << isPowerOf2(256) << endl;

    // cout << countNoOfOnes(18) << endl;


//int arr[4] = {1,2,3,4};
  //   subSet(arr, 4);


int arr[7] = {1,2,3,4,3,2,1};
cout<<uniqueNumber(arr,7);

}