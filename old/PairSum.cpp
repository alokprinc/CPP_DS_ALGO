#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i =0, j = n;

    while (i < j)
    {
        if( arr[i] + arr[j] < k){
            i++;
        } else if(arr[i] + arr[j] > k){
            j--;
        } else if(arr[i] + arr[j] == k){
            cout<< arr[i]<<" "<<arr[j];
            break;
        } else {
            cout<< k << "is not equal to any two pairSum";
            break;
        }
    }  
    
}