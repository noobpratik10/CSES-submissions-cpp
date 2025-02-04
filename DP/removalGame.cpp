#include <bits/stdc++.h>
using namespace std;

long long solveRec(int i, int j, bool first, int &n, vector<long long> &arr,
                   vector<vector<vector<long long>>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j][first] != -1)
        return dp[i][j][first];

    long long ans = (first) ? LLONG_MIN : LLONG_MAX;
    if (first)
    {
        ans = max(ans, arr[i] + solveRec(i + 1, j, !first, n, arr, dp));
        ans = max(ans, arr[j] + solveRec(i, j - 1, !first, n, arr, dp));
    }
    else
    {
        ans = min(ans, 0 + solveRec(i + 1, j, !first, n, arr, dp));
        ans = min(ans, 0 + solveRec(i, j - 1, !first, n, arr, dp));
    }
    return dp[i][j][first] = ans;
}

long long solveTab(int &n, vector<long long> &arr)
{
    vector<vector<long long>> prev(n + 1, vector<long long>(2, 0));
    vector<vector<long long>> curr(n + 1, vector<long long>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j <= n - 1; j++)
        {
            for (int first = 0; first <= 1; first++)
            {
                long long ans = (first) ? LLONG_MIN : LLONG_MAX;
                if (first)
                {
                    if (i + 1 <= j)
                        ans = max(ans, arr[i] + prev[j][!first]);
                    else
                        ans = max(ans, arr[i]);

                    if (j - 1 >= i)
                        ans = max(ans, arr[j] + curr[j - 1][!first]);
                    else
                        ans = max(ans, arr[j]);
                }
                else
                {
                    if (i + 1 <= j)
                        ans = min(ans, 0 + prev[j][!first]);
                    else
                        ans = min(ans, 0LL);

                    if (j - 1 >= i)
                        ans = min(ans, 0 + curr[j - 1][!first]);
                    else
                        ans = min(ans, 0LL);
                }
                curr[j][first] = ans;
            }
        }
        prev = curr;
    }

    return prev[n - 1][1];
}

int main()
{
    // int n;
    // cin >> n;
    // vector<long long> arr(n);
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];

    // vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(2, -1)));
    // cout << solveRec(0, n - 1, true, n, arr, dp) << endl;

    // cout << solveTab(n, arr) << endl;

    int n;
    cin >> n;
    vector<int> x(n);
    long long sum = 0;
    for (int &v : x)
    {
        cin >> v;
        sum += v;
    }

    vector<vector<long long>> dp(n, vector<long long>(n));
    for (int l = n - 1; l >= 0; l--)
    {
        for (int r = l; r < n; r++)
        {
            if (l == r)
            {
                dp[l][r] = x[l];
            }
            else
            {
                dp[l][r] = max(x[l] - dp[l + 1][r],
                               x[r] - dp[l][r - 1]);
            }
        }
    }
    cout << (sum + dp[0][n - 1]) / 2 << endl;

    return 0;
}