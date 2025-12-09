/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<int> kingdom;
vector<bool> visited;
vector<vector<int>> adj;
vector<vector<int>> revAdj;
stack<int> topoSort;

void dfs(int cur, bool firstPass, int curKingdom)
{
    visited[cur] = true;
    if (!firstPass)
    {
        kingdom[cur] = curKingdom;
    }

    auto &curAdj = (firstPass) ? adj : revAdj;
    for (auto &nbr : curAdj[cur])
    {
        if (!visited[nbr])
        {
            dfs(nbr, firstPass, curKingdom);
        }
    }

    if (firstPass)
    {
        topoSort.push(cur);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    revAdj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        revAdj[v - 1].push_back(u - 1);
    }

    kingdom.resize(n, -1);
    visited.resize(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, true, -1);
        }
    }

    visited.assign(n, false);
    int curKingdom = 1;
    while (!topoSort.empty())
    {
        auto top = topoSort.top();
        topoSort.pop();
        if (!visited[top])
        {
            dfs(top, false, curKingdom);
            curKingdom++;
        }
    }

    cout << curKingdom - 1 << endl;
    for (int i = 0; i < n; i++)
    {
        cout << kingdom[i] << " ";
    }
    cout << "\n";
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