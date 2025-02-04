#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[src] = true;

    for (auto nbr : adj[src])
    {
        if (!vis[nbr])
        {
            dfs(nbr, adj, vis);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<bool> vis(n, false);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis);
            ans.push_back(i);
        }
    }

    cout << ans.size() - 1 << endl;
    if (ans.size() >= 2)
    {
        for (int i = 0; i < ans.size() - 1; i++)
        {
            cout << ans[i] + 1 << " " << ans[i + 1] + 1 << endl;
        }
    }
    return 0;
}