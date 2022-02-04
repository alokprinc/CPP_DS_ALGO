#include <bits/stdc++.h>
using namespace std;
int counter = 0;
void sol(int n, int idx, string asf, vector<int> &vis)
{
    if (idx > n)
    {
        counter++;
        cout << counter << '.' << asf << endl;
        return;
    }
    if (vis[idx]){
        sol(n, idx + 1, asf, vis);
    }
    else{
        vis[idx] = 1;
        sol(n, idx + 1, asf + "(" + to_string(idx) + ") ", vis);
        for (int i = idx + 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                sol(n, i + 1, asf + "(" + to_string(idx) + "," + to_string(i) + ") ", vis);
                vis[i] = 0;
            }
        }
        vis[idx] = 0;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> vis(n+1, 0);
    sol(n, 1, "", vis);
}