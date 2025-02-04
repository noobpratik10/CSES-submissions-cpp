#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int solveRec(int i, int j, int &n, vector<string> &grid, vector<vector<int>> &dp)
{
    if (i == n - 1 && j == n - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (j + 1 < n && grid[i][j + 1] == '.')
        ans = (ans % mod + solveRec(i, j + 1, n, grid, dp) % mod) % mod;

    if (i + 1 < n && grid[i + 1][j] == '.')
        ans = (ans % mod + solveRec(i + 1, j, n, grid, dp) % mod) % mod;

    return dp[i][j] = ans;
}
int main()
{
    int n;
    cin >> n;

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
        cin >> grid[i];

    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*')
        cout << 0 << endl;
    else
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        cout << solveRec(0, 0, n, grid, dp) << endl;
    }

    return 0;
}