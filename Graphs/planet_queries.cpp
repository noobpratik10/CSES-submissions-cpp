/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        cin >> parent[i];
        parent[i]--;
    }

    vector<vector<int>> dp(MAX, vector<int>(n));
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = parent[j];
            }
            else
            {
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int n, k;
        cin >> n >> k;
        int current = n - 1;
        for (int i = 0; i < MAX; i++)
        {
            if (k & (1 << i))
            {
                current = dp[i][current];
            }
        }
        cout << current + 1 << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}