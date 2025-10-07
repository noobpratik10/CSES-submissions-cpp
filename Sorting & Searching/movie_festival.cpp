/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

// sort ascending
//  ----
//    ------
//        -------
//                    -------
//                    ----
//                       ---------

// ----------
// ----
//      ----------

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> mov(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> mov[i][0] >> mov[i][1];
    }
    sort(mov.begin(), mov.end());

    int ps = mov[0][0], pe = mov[0][1], cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (mov[i][0] < pe)
        {
            if (mov[i][1] < pe)
            {
                ps = mov[i][0];
                pe = mov[i][1];
            }
            else
            {
                // pass
            }
        }
        else
        {
            ps = mov[i][0];
            pe = mov[i][1];
            cnt++;
        }
    }
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    // cin>>t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}