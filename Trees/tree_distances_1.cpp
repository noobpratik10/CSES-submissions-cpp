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

void setDist(int cur, int curDist, vector<int> &dist,
             vector<bool> &vis, vector<vector<int>> &adj)
{

    vis[cur] = true;
    dist[cur] = curDist;

    for (auto &nbr : adj[cur])
    {
        if (!vis[nbr])
        {
            setDist(nbr, curDist + 1, dist, vis, adj);
        }
    }
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
    pair<int, int> ptr1 = solveRec(0, vis, adj);

    // get farthest node from farthest node  //dist node
    vis.assign(n, false);
    pair<int, int> ptr2 = solveRec(ptr1.second, vis, adj);

    // calc dist of each node from ptr1, ptr2
    vector<int> dist1(n, 0);
    vis.assign(n, false);
    setDist(ptr1.second, 0, dist1, vis, adj);
    vector<int> dist2(n, 0);
    vis.assign(n, false);
    setDist(ptr2.second, 0, dist2, vis, adj);

    for (int i = 0; i < n; i++)
    {
        cout << max(dist1[i], dist2[i]) << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}