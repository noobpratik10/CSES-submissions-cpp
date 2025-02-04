#include <bits/stdc++.h>
using namespace std;
int solveRec(int i, int j, int &n, int &m, string &a, string &b, vector<vector<int>> &dp)
{
    if (i >= n || j >= m)
    {
        if (i < n)
            return (n - i - 1);
        if (j < m)
            return (m - j - 1);
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    if (a[i] == b[j])
        ans = min(ans, 0 + solveRec(i + 1, j + 1, n, m, a, b, dp));
    ans = min(ans, 1 + solveRec(i + 1, j, n, m, a, b, dp));
    ans = min(ans, 1 + solveRec(i, j + 1, n, m, a, b, dp));
    ans = min(ans, 1 + solveRec(i + 1, j + 1, n, m, a, b, dp));
    return dp[i][j] = ans;
}

int solveTab(int &n, int &m, string &a, string &b)
{
    vector<int> prev(m + 1, INT_MAX);
    prev[m] = 0;
    for (int j = 0; j <= m - 1; j++)
        prev[j] = (m - j);

    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> curr(m + 1, INT_MAX);
        curr[m] = (n - i);
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = INT_MAX;
            if (a[i] == b[j])
                ans = min(ans, 0 + prev[j + 1]);
            ans = min(ans, 1 + prev[j]);
            ans = min(ans, 1 + curr[j + 1]);
            ans = min(ans, 1 + prev[j + 1]);
            curr[j] = ans;
        }
        prev = curr;
    }

    return prev[0];
}
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // cout << solveRec(0, 0, n, m, a, b, dp) << endl;
    cout << solveTab(n, m, a, b);
    return 0;
}