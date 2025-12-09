#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;
const int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }

    vector<ll> dist(n, INF);
    vector<ll> ways(n, 0);
    vector<ll> minFlights(n, LLONG_MAX);
    vector<ll> maxFlights(n, 0);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    dist[0] = 0;
    ways[0] = 1;
    minFlights[0] = 0;
    maxFlights[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            ll nd = d + w;
            if (nd < dist[v])
            {
                dist[v] = nd;
                ways[v] = ways[u];
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                pq.push({nd, v});
            }
            else if (nd == dist[v])
            {
                ways[v] = (ways[v] + ways[u]) % MOD;
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }

    cout << dist[n - 1] << " " << ways[n - 1] % MOD << " "
         << minFlights[n - 1] << " " << maxFlights[n - 1] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
