#include <bits/stdc++.h>
using namespace std;

bool dfs(int cur, bool team, vector<vector<int>> &adj, vector<int> &mark)
{
    if (!team)
        mark[cur] = 1;
    else
        mark[cur] = 2;

    bool ans = true;
    for (auto nbr : adj[cur])
    {
        if (mark[nbr] == 0)
        {
            ans = ans && dfs(nbr, !team, adj, mark);
        }
        else
        {
            ans = ans && (mark[nbr] != mark[cur]);
        }
    }
    return ans;
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
    vector<int> mark(n, 0);
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 0)
        {
            ans = ans && dfs(i, false, adj, mark);
        }
    }
    if (ans)
    {
        for (int i = 0; i < n; i++)
        {
            if (mark[i] == 1)
                cout << 1 << " ";
            else
                cout << 2 << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}