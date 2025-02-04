#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int solveRec(int x, int &n, vector<int> &arr, vector<int> &dp)
{
    if (x == 0)
        return 1;
    if (dp[x] != -1)
    {
        return dp[x];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (x - arr[i] >= 0)
        {
            ans = (solveRec(x - arr[i], n, arr, dp) % mod + ans % mod) % mod;
        }
    }
    return dp[x] = ans;
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
    vector<int> dp(x + 1, -1);
    cout << solveRec(x, n, arr, dp) << endl;
    return 0;
}