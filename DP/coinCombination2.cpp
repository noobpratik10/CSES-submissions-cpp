#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int solveRec(int x, int index, int &n, vector<int> &arr, vector<vector<int>> &dp)
{
    if (x == 0)
    {
        return 1;
    }
    if (index >= n || arr[index] > x)
    {
        return 0;
    }

    if (dp[x][index] != -1)
        return dp[x][index];

    int ans = 0;
    if (x - arr[index] >= 0)
    {
        ans = (ans % mod + solveRec(x - arr[index], index, n, arr, dp) % mod) % mod;
    }
    ans = (ans % mod + solveRec(x, index + 1, n, arr, dp)) % mod;
    return dp[x][index] = ans;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<vector<int>> dp(x + 1, vector<int>(n + 1, -1));
    cout << solveRec(x, 0, n, arr, dp) << endl;
    return 0;
}