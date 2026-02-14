/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Edge
{
public:
    int to;    // target vertex
    ll cap;    // remaining capcity (residual capacity)
    ll revInd; // index of the reverse edge in graph[to]

    Edge(int _to, ll _cap, ll _revInd)
    {
        to = _to;
        cap = _cap;
        revInd = _revInd;
    }
};

class Dinic
{
public:
    int n;
    vector<vector<Edge>> levelG; // level graph
    vector<int> level;           // dist from src in level graph
    vector<int> itr;             // current edge iterator for each node (to prune)

    Dinic(int _n)
    {
        n = _n;
        levelG.resize(n);
        level.resize(n);
        itr.resize(n);
    }

    // return the idx of g[u] so that the caller can remember it
    int addEdge(int u, int v, ll cap)
    {
        // add directed edge u --> v with capcity cap
        levelG[u].push_back(Edge(v, cap, levelG[v].size()));
        // add directed edge from v --> u with capacity 0 initially
        levelG[v].push_back(Edge(u, 0ll, levelG[u].size() - 1));

        return (int)(levelG[u].size() - 1);
    }

    // Build level graph using BFS, return true if sink d is reachable
    bool bfs(int src, int dest)
    {
        level.assign(n, -1);

        queue<int> q;
        level[src] = 0;
        q.push(src);

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for (auto &nbr : levelG[cur])
            {
                if (level[nbr.to] == -1 && nbr.cap > 0)
                {
                    level[nbr.to] = level[cur] + 1;
                    q.push(nbr.to);
                }
            }
        }

        return (level[dest] != -1);
    }

    // DFS to send flow in level graph & return the amount pushed
    ll dfs(int cur, int dest, ll flow)
    {
        if (cur == dest)
        {
            return flow;
        }

        // start from the last unused edge for this node for current dfs run
        for (int &i = itr[cur]; i < (int)levelG[cur].size(); i++)
        {

            Edge &nbr = levelG[cur][i];
            if (nbr.cap <= 0)
                continue; // no residual capacity left
            if (level[nbr.to] != level[cur] + 1)
                continue; // must go to next level only

            // go to next level with bottleneck flow
            ll flowPushed = dfs(nbr.to, dest, min(flow, nbr.cap));

            // update the capacities with the already pushed flow
            if (flowPushed > 0)
            {
                nbr.cap -= flowPushed;
                levelG[nbr.to][nbr.revInd].cap += flowPushed;
                return flowPushed;
            }
        }

        return 0;
    }

    // Compute max flow from src to dest
    ll getMaxFlow(int src, int dest)
    {
        // build-rebuild level graph until path exist
        ll flow = 0;
        while (bfs(src, dest))
        {

            // push flow until capacity reached for this level graph
            itr.assign(n, 0);
            while (true)
            {
                ll curFlow = dfs(src, dest, LLONG_MAX);
                if (curFlow == 0)
                    break;
                flow += curFlow;
            }
        }
        return flow;
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int S, offsetB, offsetG, T, N;
    S = 0;           // source
    offsetB = 1;     // boys nodes
    offsetG = 1 + n; // girls nodes
    T = 1 + n + m;   // sink
    N = T + 1;       // no of nodes in flow network
    Dinic dinic(N);

    // connect src --> boys
    for (int b = 0; b < n; b++)
    {
        int idxS = dinic.addEdge(S, offsetB + b, 1ll);
    }

    // connect boys --> girls by reading possible pairs with cap=1
    // list to get the index of the edge btw boy --> girl, to get the ans later
    vector<vector<int>> edgeIndList;
    for (int i = 0; i < k; i++)
    {
        int b, g;
        cin >> b >> g;
        b--;
        g--;
        int idxB = dinic.addEdge(offsetB + b, offsetG + g, 1ll);
        // record edge for later: boyNode, girlNode, Index
        edgeIndList.push_back({offsetB + b, offsetG + g, (int)idxB});
    }

    // connect girls --> sink
    for (int g = 0; g < m; g++)
    {
        int idxG = dinic.addEdge(offsetG + g, T, 1ll);
    }

    // compute the max flow
    ll maxFlow = dinic.getMaxFlow(S, T);

    // get all saturated edges from boys --> girls. Those are
    // all the max possible pairs
    vector<pair<int, int>> result;
    for (auto &e : edgeIndList)
    {
        int boy = e[0], girl = e[1], ind = e[2];
        auto &levelEdge = dinic.levelG[boy][ind];

        if (levelEdge.cap == 0)
        { // forward edge was saturated --> matched
            int boyId = boy - offsetB + 1;
            int girlId = girl - offsetG + 1;
            result.push_back({boyId, girlId});
        }
    }

    // output
    cout << result.size() << endl;
    for (auto &i : result)
    {
        cout << i.first << " " << i.second << endl;
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