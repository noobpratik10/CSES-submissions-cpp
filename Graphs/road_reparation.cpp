/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<int> parent;
vector<int> _rank;

int findParent(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

void unionByRank(int x, int y)
{
    int parX = findParent(x);
    int parY = findParent(y);

    if (_rank[parX] >= _rank[parY])
    {
        _rank[parX] += _rank[parY];
        parent[parY] = parX;
    }
    else
    {
        _rank[parY] += _rank[parX];
        parent[parX] = parY;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(m, vector<ll>(3));
    vector<bool> visited(n, false);
    parent.assign(n, -1);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    _rank.assign(n, 0);
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u - 1, v - 1};
    }

    sort(edges.begin(), edges.end());
    ll minCost = 0;
    ll count = 0;
    for (auto &e : edges)
    {
        int parX = findParent(e[1]);
        int parY = findParent(e[2]);
        if (parX != parY)
        {
            unionByRank(e[1], e[2]);
            minCost += e[0];
            count++;
        }
    }

    if (count != n - 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << minCost << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}