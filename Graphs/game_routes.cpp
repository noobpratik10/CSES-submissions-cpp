/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

void solve()
{
    int n, m;
    cin >> n >> m;

    // build adj list & indeg
    vector<vector<int>> adj(n);
    vector<int> inDeg(n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        inDeg[v - 1]++;
    }
    // get topoSort
    queue<int> q;
    vector<int> topoSort;
    for (int i = 0; i < n; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        topoSort.push_back(q.front());
        q.pop();

        for (auto nbr : adj[topoSort.back()])
        {
            inDeg[nbr]--;
            if (inDeg[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }

    // get longest path with dp
    vector<int> dp(n, 0);
    dp[0] = 1;

    for (auto u : topoSort)
    {
        for (auto v : adj[u])
        {
            dp[v] = (dp[v] % mod + dp[u] % mod) % mod;
        }
    }

    // print ans
    cout << dp[n - 1] << endl;
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