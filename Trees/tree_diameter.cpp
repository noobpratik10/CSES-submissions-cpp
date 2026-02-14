/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> solveRec(int cur, vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[cur] = true;
    pair<int, int> curAns = {0, cur};
    for (auto &nbr : adj[cur])
    {
        if (!vis[nbr])
        {
            pair<int, int> curNbrAns = solveRec(nbr, vis, adj);
            if (1 + curNbrAns.first > curAns.first)
            {
                curAns.first = 1 + curNbrAns.first;
                curAns.second = curNbrAns.second;
            }
        }
    }
    return curAns;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    // get ferthest node from 0  //dist node
    vector<bool> vis(n, false);
    pair<int, int> ans = solveRec(0, vis, adj);
    // get farthest node from farthest node  //dist node
    vis.assign(n, false);
    ans = solveRec(ans.second, vis, adj);
    cout << ans.first << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}