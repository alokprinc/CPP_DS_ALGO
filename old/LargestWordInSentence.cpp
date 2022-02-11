#include <iostream>
using namespace std;

int main()
{
    int currentLen = 0, mx = 0;
    char arr[] = {"My name is prince"};
    char sol[14];
    int s = 0, e = 0;

    int i = 0;
    while (1)
    {

        if (arr[i] == ' ' || arr[i] == ('\0'))
        {
            if (currentLen > mx)
            {
                mx = currentLen;
                
               
            }
            currentLen = 0;
            cout<<i<<" ";
        }
        else
            currentLen++;

        if (arr[i] == '\0')
            break;

        i++;
    }
    cout << mx;
}