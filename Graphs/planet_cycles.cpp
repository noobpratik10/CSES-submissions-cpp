/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> dist;
vector<int> ans;
vector<int> adj;
vector<bool> vis;
int cycle_start = -1;
int cycle_size = 0;

void dfs(int node, int curDist)
{
    if (vis[node])
    {
        return;
    }
    vis[node] = true;
    dist[node] = curDist;
    int nbr = adj[node];
    if (!vis[nbr])
    {
        dfs(nbr, curDist + 1);
    }
    else
    {
        if (ans[nbr] == 0)
        { // its cycle size not calculated yet, we are in cycle
            cycle_start = nbr;
            cycle_size = dist[node] - dist[nbr] + 1;
        }
        else
        { // its size is already set, we are not in cycle
            cycle_size = ans[nbr];
        }
    }

    // get ans
    if (cycle_start != -1)
    {
        ans[node] = cycle_size;
        if (node == cycle_start)
        {
            cycle_start = -1;
        }
    }
    else
    {
        ans[node] = ans[nbr] + 1;
    }
}
void solve()
{
    int n;
    cin >> n;
    dist.resize(n, 0);
    ans.resize(n, 0);
    adj.resize(n, 0);
    vis.resize(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> adj[i];
        adj[i]--;
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cycle_start = -1;
            cycle_size = 0;
            dfs(i, 0);
        }
    }

    for (auto &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    t = 1; // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}