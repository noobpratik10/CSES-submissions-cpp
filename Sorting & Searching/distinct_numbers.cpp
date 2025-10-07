/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    cout << cnt.size() << endl;
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