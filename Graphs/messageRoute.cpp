#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int &n, vector<vector<int>> &adj)
{
    vector<int> dist(n, INT_MAX);
    vector<int> par(n, -1);
    set<vector<int>> st; // dist x

    st.insert({0, 0});
    dist[0] = 0;
    vector<int> ans;

    while (!st.empty())
    {
        auto top = *(st.begin());
        st.erase(st.begin());

        int curDist = top[0];
        int i = top[1];

        if (n - 1 == i)
            break;

        for (auto nbr : adj[i])
        {
            if (dist[nbr] > curDist + 1)
            {
                auto prevRec = st.find({dist[nbr], nbr});
                if (prevRec != st.end())
                    st.erase(prevRec);

                dist[nbr] = curDist + 1;
                par[nbr] = i;
                st.insert({dist[nbr], nbr});
            }
        }
    }

    if (dist[n - 1] == INT_MAX)
        return ans;
    else
    {
        int i = n - 1;
        while (true)
        {
            ans.push_back(i);
            if (i == 0)
                break;
            else
                i = par[i];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<int> ans = dijkstra(n, adj);
    if (ans.empty())
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << ans.size() << endl;
        for (auto i : ans)
            cout << i + 1 << " ";
        cout << endl;
    }
    return 0;
}