/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int> mst;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mst.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int cust;
        cin >> cust;

        auto it = mst.upper_bound(cust);
        if (it == mst.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            it--;
            cout << *it << endl;
            mst.erase(it);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}