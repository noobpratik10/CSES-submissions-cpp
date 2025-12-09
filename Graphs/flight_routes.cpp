#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
    }

    vector<priority_queue<ll>> KMinDist(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, 0});
    KMinDist[0].push(0);

    while (!pq.empty())
    {
        auto [curDist, cur] = pq.top();
        pq.pop();

        // If this distance is already not among the best k, skip
        if (KMinDist[cur].top() < curDist && KMinDist[cur].size() == k)
            continue;

        for (auto &[v, w] : adj[cur])
        {
            ll newDist = curDist + w;

            if (KMinDist[v].size() < k || KMinDist[v].top() > newDist)
            {
                KMinDist[v].push(newDist);
                if (KMinDist[v].size() > k)
                    KMinDist[v].pop();
                pq.push({newDist, v});
            }
        }
    }

    vector<ll> ans;
    while (!KMinDist[n - 1].empty())
    {
        ans.push_back(KMinDist[n - 1].top());
        KMinDist[n - 1].pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto d : ans)
        cout << d << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
