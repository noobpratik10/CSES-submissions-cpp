#include <bits/stdc++.h>
using namespace std;

long long solveRec(long long x, long long &n, vector<long long> &arr, vector<long long> &dp)
{
    if (x == 0)
        return 0;
    if (dp[x] != -1)
        return dp[x];

    long long ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (x - arr[i] >= 0)
        {
            ans = min(ans, 1 + solveRec(x - arr[i], n, arr, dp));
        }
    }

    return dp[x] = ans;
}

int main()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    // sort(arr.begin(), arr.end());
    vector<long long> dp(x + 1, -1);
    long long ans = solveRec(x, n, arr, dp);
    if (ans >= INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}