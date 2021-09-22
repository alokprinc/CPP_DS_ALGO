#include <bits/stdc++.h>
using namespace std;

long long solve(int i, int j, int arr[])
{   
    
    if(i == j)
        return arr[i];

    if (i > j)
    {
        return 0;
    }

    int l = arr[i] + min(solve(i + 2, j, arr), solve(i + 1, j - 1, arr));
    int r = arr[j] + min(solve(i + 1, j - 1, arr), solve(i, j - 2, arr));

    return max(l, r);
}
long long maximumAmount(int arr[], int n)
{

    return solve(0, n - 1, arr);
}

int main()
{
    int N = 4;
    int A[] = {5, 3, 7, 10};
    //Output: 15
    cout<<maximumAmount(A,N);
}
