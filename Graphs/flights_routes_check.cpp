/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;

void dfs(int node, vector<vector<int>> &adj)
{
    visited[node] = true;

    for (auto &nbr : adj[node])
    {
        if (!visited[nbr])
        {
            dfs(nbr, adj);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<vector<int>> revAdj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        revAdj[v - 1].push_back(u - 1);
    }

    visited.assign(n, 0);
    dfs(0, adj);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "NO" << endl;
            cout << 1 << " " << i + 1 << endl;
            return;
        }
    }
    visited.assign(n, 0);
    dfs(0, revAdj);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "NO" << endl;
            cout << i + 1 << " " << 1 << endl;
            return;
        }
    }
    cout << "YES" << endl;
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