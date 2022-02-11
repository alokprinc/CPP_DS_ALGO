// C++ program to demonstrate default behaviour of
// sort() in STL.
#include <bits/stdc++.h>
using namespace std;

int main()
{int n;
cin>>n;
	int arr[n] ;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	

	/*Here we take two parameters, the beginning of the
	array and the length n upto which we want the array to
	be sorted*/
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	return 0;
}
