#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    vector<string> result(n, string(m, '#'));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Choose set depending on checkerboard
            if ((i + j) % 2 == 0)
            {
                // Try 'A', else use 'B'
                result[i][j] = (grid[i][j] == 'A' ? 'B' : 'A');
            }
            else
            {
                // Try 'C', else use 'D'
                result[i][j] = (grid[i][j] == 'C' ? 'D' : 'C');
            }
        }
    }

    // Print result
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
