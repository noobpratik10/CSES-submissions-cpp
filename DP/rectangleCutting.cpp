#include <bits/stdc++.h>
using namespace std;

int solveRec(int n, int m, vector<vector<int>> &dp)
{
    if (n == m)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];

    int ans = INT_MAX;
    for (int i = 1; i <= n / 2; i++)
        ans = min(ans, 1 + solveRec(i, m, dp) + solveRec(n - i, m, dp));
    for (int j = 1; j <= m / 2; j++)
        ans = min(ans, 1 + solveRec(n, j, dp) + solveRec(n, m - j, dp));
    return dp[n][m] = ans;
}

int solveTab(int N, int M)
{
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, INT_MAX));
    for (int x = 0; x <= min(N, M); x++)
        dp[x][x] = 0;

    for (int n = 1; n <= N; n++)
    {
        for (int m = 1; m <= M; m++)
        {
            if (n == m)
                continue;
            int ans = INT_MAX;
            for (int i = 1; i <= n / 2; i++)
                ans = min(ans, 1 + dp[i][m] + dp[n - i][m]);
            for (int j = 1; j <= m / 2; j++)
                ans = min(ans, 1 + dp[n][j] + dp[n][m - j]);
            dp[n][m] = ans;
        }
    }

    return dp[N][M];
}

int main()
{
    int n, m;
    cin >> n >> m;
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // cout << solveRec(n, m, dp) << endl;
    cout << solveTab(n, m);
    return 0;
}