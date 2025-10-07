#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            // Collect numbers used in same row (left) and same col (above)
            vector<bool> used(n * 2, false); // enough space for mex values
            for (int k = 0; k < c; k++)
                used[ans[r][k]] = true;
            for (int k = 0; k < r; k++)
                used[ans[k][c]] = true;

            // Find mex
            int mex = 0;
            while (used[mex])
                mex++;

            ans[r][c] = mex;
        }
    }

    // Print result
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cout << ans[r][c] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
