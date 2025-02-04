#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int n, int m, vector<string> &mat)
{
    mat[i][j] = '&';

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto d : dir)
    {
        int ni = i + d[0];
        int nj = j + d[1];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] == '.')
        {
            dfs(ni, nj, n, m, mat);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++)
        cin >> mat[i];

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.')
            {
                dfs(i, j, n, m, mat);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}