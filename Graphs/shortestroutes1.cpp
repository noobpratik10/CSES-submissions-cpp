#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
    }

    vector<long long> dist(n, 1e18);
    set<pair<long long, int>> st; // dist, city
    dist[0] = 0;
    st.insert({0, 0});

    while (!st.empty())
    {
        auto cur = *st.begin();
        st.erase(st.begin());

        for (auto nbr : adj[cur.second])
        {
            if (dist[cur.second] + nbr[1] < dist[nbr[0] * 1ll])
            {
                auto prevRec = st.find({dist[nbr[0]], nbr[0]});
                if (prevRec != st.end())
                    st.erase(prevRec);

                dist[nbr[0]] = dist[cur.second] + nbr[1];
                st.insert({dist[nbr[0]], nbr[0]});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}