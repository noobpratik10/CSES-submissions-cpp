#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int solveRec(int cur, int &n, int target, vector<vector<int>> &dp)
{
    if (cur > n)
        return (target == 0);
    if (dp[cur][target] != -1)
        return dp[cur][target];

    int ans = 0;
    if (target - cur >= 0)
        ans = (ans + solveRec(cur + 1, n, target - cur, dp)) % mod;
    ans = (ans + solveRec(cur + 1, n, target, dp)) % mod;
    return dp[cur][target] = ans;
}

int main()
{
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2 == 0)
    {
        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));
        int result = solveRec(1, n, sum / 2, dp);

        // Correctly divide by 2 using modular inverse of 2 under mod
        result = (result * 1LL * 500000004) % mod;

        cout << result << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}
