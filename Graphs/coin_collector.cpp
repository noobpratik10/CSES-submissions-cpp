/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<vector<int>> graph, revGraph, sccGraph;
vector<ll> coins;
vector<bool> visited;
stack<int> finishStack;
vector<int> sccId;
vector<ll> sccSum;
vector<int> inDeg;
queue<int> q;
vector<int> topoSort;
vector<ll> dp;

void dfsForward(int cur)
{
    visited[cur] = true;

    for (auto &nbr : graph[cur])
    {
        if (!visited[nbr])
        {
            dfsForward(nbr);
        }
    }

    finishStack.push(cur);
}

ll dfsReverse(int cur, int curId)
{
    sccId[cur] = curId;

    ll sum = coins[cur];
    for (auto &nbr : revGraph[cur])
    {
        if (sccId[nbr] == -1)
        {
            sum += dfsReverse(nbr, curId);
        }
    }

    return sum;
}

void buildCondensedGraph(int n)
{
    for (int cur = 0; cur < n; cur++)
    {
        for (auto &nbr : graph[cur])
        {
            if (sccId[cur] != sccId[nbr])
            {
                sccGraph[sccId[cur]].push_back(sccId[nbr]);
            }
        }
    }
}

void getTopoSortKahn(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (auto &nbr : sccGraph[i])
        {
            inDeg[nbr]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        topoSort.push_back(cur);

        for (auto &nbr : sccGraph[cur])
        {
            inDeg[nbr]--;
            if (inDeg[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }
}

void solve()
{
    // get input
    int n, m;
    cin >> n >> m;

    coins.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    graph.resize(n);
    revGraph.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        revGraph[b].push_back(a);
    }

    // get scc
    visited.resize(n);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsForward(i);
        }
    }

    sccId.resize(n, -1);
    int curId = 0;
    while (!finishStack.empty())
    {
        int cur = finishStack.top();
        finishStack.pop();
        ll curSum = coins[cur];
        if (sccId[cur] == -1)
        {
            curSum = dfsReverse(cur, curId);
        }
        sccSum.push_back(curSum);
        dp.push_back(curSum);
        curId++;
    }

    // build condensed graph
    sccGraph.resize(curId);
    buildCondensedGraph(curId);

    // get toposort
    inDeg.resize(curId);
    getTopoSortKahn(curId);

    // get dp on toposort
    for (int i = 0; i < curId; i++)
    {
        for (auto &nbr : sccGraph[topoSort[i]])
        {
            dp[nbr] = max(dp[nbr], dp[topoSort[i]] + sccSum[nbr]);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
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