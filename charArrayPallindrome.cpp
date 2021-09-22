#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char arr[n + 1];
    cin >> arr;

    int i = 0, j = n-1;
    bool p =false;
    while (i < n && j > 0)
    {
        if (arr[i] == arr[j])
        {
            p = true;
        }
        else
        {
            cout << "Not Pallindrome";
            break;
        }
        i++;
        j--;
    }
    if(p) cout<<"Pallindrome";
}