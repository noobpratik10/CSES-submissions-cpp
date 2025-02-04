#include <bits/stdc++.h>
using namespace std;

int solveRec(int index, int x, int &n, vector<int> &prices, vector<int> &pages, vector<vector<int>> &dp)
{
    if (index >= n || x == 0)
        return 0;
    if (dp[index][x] != -1)
        return dp[index][x];

    int ans = 0;
    if (x - prices[index] >= 0)
        ans = max(ans, pages[index] + solveRec(index + 1, x - prices[index], n, prices, pages, dp));
    ans = max(ans, 0 + solveRec(index + 1, x, n, prices, pages, dp));

    return dp[index][x] = ans;
}

int solveTab(int n, int X, vector<int> &prices, vector<int> &pages)
{
    // vector<vector<int>> dp(n + 1, vector<int>(X + 1, 0));
    vector<int> prev(X + 1, 0);
    vector<int> curr(X + 1, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int x = 0; x <= X; x++)
        {
            int ans = 0;
            if (x - prices[index] >= 0)
                ans = max(ans, pages[index] + prev[x - prices[index]]);
            ans = max(ans, 0 + prev[x]);

            curr[x] = ans;
        }
        prev = curr;
    }

    return prev[X];
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    // vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    // cout << solveRec(0, x, n, prices, pages, dp) << endl;
    cout << solveTab(n, x, prices, pages) << endl;
    return 0;
}