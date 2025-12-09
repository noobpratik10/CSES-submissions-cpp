/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> inDeg(n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        inDeg[v - 1]++;
    }

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

    if (topoSort.size() != n)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (auto i : topoSort)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
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