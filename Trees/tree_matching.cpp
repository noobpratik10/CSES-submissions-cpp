/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

// NO DP, simple dfs --> return 2 answers, include edge cur, excluding edge cur
// dp[u][0]  --> max edge for tree with root u, and exlcuding any edge with node u
// dp[u][1]  --> max edge for tree with root u, and including anyone max edge with node u
pair<int, int> solveRec(int cur, int par,
                        vector<vector<int>> &adj)
{
    // get children answers and their pref, suf sum
    vector<pair<int, int>> childrenAns;
    int childNo = 0;
    for (auto &child : adj[cur])
    {
        if (child == par)
            continue;
        pair<int, int> curChildAns = solveRec(child, cur, adj);
        childrenAns.push_back(curChildAns);
        childNo++;
    }

    // get pref , suf sum for easy calc of answers
    int m = childNo; // get the of children excluding parent
    vector<int> prefSum(m + 1, 0), sufSum(m + 1, 0);

    for (int i = 0; i < m; i++)
    {
        prefSum[i + 1] = prefSum[i] +
                         max(childrenAns[i].first, childrenAns[i].second);
    }

    for (int i = m - 2; i >= 0; i--)
    {
        sufSum[i] = sufSum[i + 1] +
                    max(childrenAns[i + 1].first, childrenAns[i + 1].second);
    }

    // formulate cur ans
    pair<int, int> curAns = {0, 0};
    // case 1: include anyone edge with cur which gives max no of edges
    for (int i = 0; i < m; i++)
    {
        // rest child max all+this child exclude ans
        // this edge+ all prev max+all suf max+ this children node excl.
        curAns.second = max(curAns.second,
                            1 + prefSum[i] + sufSum[i] + childrenAns[i].first);
    }
    // case 2:exclude all edges with cur
    // ans will be sum of max of all children
    curAns.first = prefSum[m];

    return curAns; // exclude include
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
    // start with root 0, par null -1
    pair<int, int> ans = solveRec(0, -1, adj);
    cout << max(ans.first, ans.second) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}