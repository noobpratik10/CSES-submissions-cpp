/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 18;

void dfs(int node, vector<bool> &visited, vector<int> &parent, vector<int> &len, vector<vector<int>> &binaryLifting)
{
    if (visited[node])
    {
        return;
    }
    visited[node] = true;

    // process par first
    dfs(parent[node], visited, parent, len, binaryLifting);

    // fill binaryL arr for node
    binaryLifting[node][0] = parent[node];
    for (int i = 1; i < MAX; i++)
    {
        binaryLifting[node][i] = binaryLifting[binaryLifting[node][i - 1]][i - 1];
    }

    // get len for node
    len[node] = len[binaryLifting[node][0]] + 1;
}

int jump(int a, int k, vector<vector<int>> &binaryLifting)
{
    if (k < 0)
    {
        return -1;
    }

    int current = a;
    for (int i = 0; i < MAX; i++)
    {
        if (k & (1 << i))
        {
            current = binaryLifting[current][i];
        }
    }
    return current;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        cin >> parent[i];
        parent[i]--;
    }

    // fill len and binaryL array
    vector<vector<int>> binaryLifting(n, vector<int>(MAX));
    vector<int> len(n, 0); // dist to cycleentrypt
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, parent, len, binaryLifting);
        }
    }

    // process queries
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int cycleEntryPtA = jump(a, len[a], binaryLifting);
        // case 1:- b is in path of a to cycleentrypt
        if (jump(a, len[a] - len[b], binaryLifting) == b)
        {
            cout << len[a] - len[b] << endl;
        }
        // case 2:- b is on cycle reachable from a's cycle entry point
        else if (jump(cycleEntryPtA, len[cycleEntryPtA] - len[b], binaryLifting) == b)
        {
            cout << len[a] + len[cycleEntryPtA] - len[b] << endl;
        }
        // case 3:- no path btw a and b
        else
        {
            cout << -1 << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}