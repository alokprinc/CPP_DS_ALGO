#include <bits/stdc++.h>
using namespace std;
void permute(vector<int> box, int cr, int r)
{
    if (cr > r)
    {
        for (auto a : box)
        {
            cout << a;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < box.size(); i++)
    {
        if (box[i] == 0)
        {
            box[i] = cr;
            permute(box, cr + 1, r);
            box[i] = 0;
        }
    }
}
int main()
{
    int boxes, items;
    cin >> boxes >> items;

    vector<int> box(boxes, 0);
    permute(box, 1, items);
}