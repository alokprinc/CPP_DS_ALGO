#include <bits/stdc++.h>
using namespace std;
class Pair
{
public:
    int prime, pointer, val;
};
struct mycomp
{
    bool operator()(Pair a,
                    Pair b)
    {
        return a.val > b.val;
    }
};
void sol(vector<int> primes, int n)
{

    priority_queue < Pair, vector<Pair>, mycomp> q;
    for (int i = 0; i < primes.size(); i++)
    {
        q.push({primes[i], 1, 1 * primes[i]});
    }

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n + 1;)
    {
        Pair rem = q.top();
        q.pop();

        if (rem.val != dp[i - 1])
        {
            dp[i] = rem.val;
            i++;
        }
        q.push({rem.prime, rem.pointer + 1, rem.prime * dp[rem.pointer + 1]});
    }
    cout<<dp[n]<<endl;
}
int main()
{

    int k;
    cin >> k;
    vector<int> primes(k);
    for (int i = 0; i < k; i++)
    {
        cin >> primes[i];
    }

    int n;
    cin >> n;
    sol(primes, n);
}