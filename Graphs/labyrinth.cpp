#include <bits/stdc++.h>
using namespace std;

string dijkstra(vector<int> &start, vector<int> &end, int &n, int &m, vector<string> &mat)
{
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<vector<int>>> par(n, vector<vector<int>>(m, vector<int>(2, -1)));
    set<vector<int>> st; // dist x y
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    st.insert({0, start[0], start[1]});
    dist[start[0]][start[1]] = 0;
    string ans;

    while (!st.empty())
    {
        auto top = *(st.begin());
        st.erase(st.begin());

        int curDist = top[0];
        int i = top[1];
        int j = top[2];

        if (end[0] == i && end[1] == j)
            break;

        for (auto d : dir)
        {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && (mat[ni][nj] == '.' || mat[ni][nj] == 'B'))
            {
                if (dist[ni][nj] > curDist + 1)
                {
                    auto prevRec = st.find({dist[ni][nj], ni, nj});
                    if (prevRec != st.end())
                        st.erase(prevRec);

                    dist[ni][nj] = curDist + 1;
                    par[ni][nj] = {i, j};
                    st.insert({dist[ni][nj], ni, nj});
                }
            }
        }
    }

    if (dist[end[0]][end[1]] == INT_MAX)
        return "";
    else
    {
        string ans;

        int i = end[0], j = end[1];
        while (true)
        {
            int pi = par[i][j][0], pj = par[i][j][1];
            if (i == start[0] && j == start[1])
                break;
            if (pi < i && pj == j)
                ans += 'D';
            else if (pi == i && pj < j)
                ans += 'R';
            else if (pi == i && pj > j)
                ans += 'L';
            else
                ans += 'U';

            i = pi, j = pj;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    vector<int> start;
    vector<int> end;
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
        for (int j = 0; j < mat[i].length(); j++)
        {
            if (mat[i][j] == 'A')
                start = {i, j};
            else if (mat[i][j] == 'B')
                end = {i, j};
        }
    }

    string ans = dijkstra(start, end, n, m, mat);
    if (ans.empty())
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        cout << ans.length() << endl;
        cout << ans << endl;
    }
    return 0;
}