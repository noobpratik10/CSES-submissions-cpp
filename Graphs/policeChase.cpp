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

    void addEdge(int u, int v, ll cap)
    {
        // add directed edge u --> v with capcity cap
        levelG[u].push_back(Edge(v, cap, levelG[v].size()));
        // add directed edge from v --> u with capacity 0 initially
        levelG[v].push_back(Edge(u, 0ll, levelG[u].size() - 1));
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

    // After max flow, find the nodes reachable from src in residual graph
    vector<bool> getReachableFromSrc(int src)
    {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for (auto &nbr : levelG[cur])
            {
                if (!visited[nbr.to] && nbr.cap > 0)
                {
                    q.push(nbr.to);
                    visited[nbr.to] = true;
                }
            }
        }

        return visited;
    }
};

void solve()
{
    // 1. Build residual network
    int n, m;
    cin >> n >> m;
    Dinic dinic(n);
    vector<pair<int, int>> edges(n);
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        dinic.addEdge((int)a, (int)b, 1);
        dinic.addEdge((int)b, (int)a, 1);
        edges.push_back({a, b});
    }

    // 2. Compute max flow using Dinic's Algo
    ll maxFlow = dinic.getMaxFlow(0, n - 1);

    // 3. Get the reachable node from the src in final residual network
    vector<bool> reachable = dinic.getReachableFromSrc(0);

    // 4. Find the edges crossing from reachable --> not reachable
    vector<pair<int, int>> cut;
    for (auto &e : edges)
    {
        if ((reachable[e.first] && !reachable[e.second]) ||
            (!reachable[e.first] && reachable[e.second]))
        {
            cut.push_back(e);
        }
    }

    // 5. Output
    cout << cut.size() << endl;
    for (auto &c : cut)
    {
        cout << c.first + 1 << " " << c.second + 1 << endl;
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
