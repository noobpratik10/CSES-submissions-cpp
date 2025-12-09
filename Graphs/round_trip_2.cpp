#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dfs(int cur, vector<bool> &vis, vector<bool> &inStack, vector<int> &curPath, vector<vector<int>> &adj)
{
    vis[cur] = true;
    curPath.push_back(cur);
    inStack[cur] = true;

    int ans = -1;
    for (auto &nbr : adj[cur])
    {
        if (!vis[nbr])
        {
            ans = dfs(nbr, vis, inStack, curPath, adj);
            if (ans != -1)
            {
                return ans;
            }
        }
        else if (inStack[nbr])
        {
            curPath.push_back(nbr);
            return nbr;
        }
    }

    curPath.pop_back();
    inStack[cur] = false;
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }

    vector<int> curPath;
    vector<bool> vis(n, false);
    vector<bool> inStack(n, false);
    int head = -1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            head = dfs(i, vis, inStack, curPath, adj);
            if (head != -1)
                break;
        }
    }
    if (curPath.empty())
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int ind = 0;
    for (; ind < curPath.size(); ind++)
    {
        if (curPath[ind] == head)
        {
            break;
        }
    }
    cout << curPath.size() - ind << endl;
    while (ind < curPath.size())
    {
        cout << curPath[ind] + 1 << " ";
        ind++;
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
