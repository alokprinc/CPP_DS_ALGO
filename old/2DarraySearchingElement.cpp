#include <iostream>
using namespace std;
//   O(N + M)
int main()
{

    int n, m;
    int x;
    cin >> n >> m >> x;
    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int i = 0, j = m;
    bool found = false;
    while (i < n && j > 0)
    {
        if (arr[i][j] == x)
        {
            
            found = true;
        }
        if (arr[i][j] > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    if (found)
        cout << "value Present at " << i << " " << j;
      else
      cout<<"NOT FOUND";  
}