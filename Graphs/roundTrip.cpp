#include <bits/stdc++.h>
using namespace std;

void fill(vector<int> &cycle, int &c, int nbr, vector<int> &vpar)
{
    if (nbr == c)
        return;
    fill(cycle, c, vpar[nbr], vpar);
    cycle.push_back(nbr);
}

bool dfs(int cur, int par, int &n, vector<bool> &vis, vector<vector<int>> &adj,
         vector<int> &vpar)
{
    vis[cur] = true;
    vpar[cur] = par;

    for (auto nbr : adj[cur])
    {
        if (!vis[nbr])
        {
            bool ans = dfs(nbr, cur, n, vis, adj, vpar);
            if (ans > 0)
                return ans;
        }
        else if (vis[nbr] && nbr != par)
        {
            int c = cur;
            vector<int> cycle;
            while (true)
            {
                cycle.push_back(c + 1);
                if (c == nbr)
                    break;
                c = vpar[c];
            }
            cycle.push_back(cur + 1);
            cout << cycle.size() << endl;
            for (auto i : cycle)
                cout << i << " ";
            cout << endl;
            return true;
        }
    }
    return 0;
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
    vector<int> vpar(n, -1);
    bool ans = false;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            ans = ans || dfs(i, -1, n, vis, adj, vpar);
    if (!ans)
        cout << "IMPOSSIBLE" << endl;

    return 0;
}