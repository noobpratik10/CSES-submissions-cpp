#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long solveRec(long long sum, long long &n, vector<long long> &dp)
{
    if (sum > n)
        return 0;
    if (sum == n)
        return 1;
    if (dp[sum] != -1)
        return dp[sum];

    long long ans = 0;
    for (long long d = 1; d <= 6; d++)
    {
        ans = (solveRec(sum + d, n, dp) % mod + ans % mod) % mod;
    }
    return dp[sum] = ans;
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> dp(6 * n + 1, -1);
    cout << solveRec(0, n, dp) << endl;
    return 0;
}