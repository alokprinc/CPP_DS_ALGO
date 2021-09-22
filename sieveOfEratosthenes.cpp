#include <iostream>
using namespace std;

void isPrime(int n)
{

    bool isPrime[n] = {0} ;

    // for (int i = 0; i < n; i++)
    // {
    //     isPrime[i] = true;
    // }

    for (int i = 2; i * i <= n; i++)
    {

        for (int j = 2 * i; j <= n; j += i)
        {
            isPrime[j] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (isPrime[i] == 0)
            cout << i << " ";
    }
}

int main()
{
    int n;

    cin >> n;

    isPrime(n);
}