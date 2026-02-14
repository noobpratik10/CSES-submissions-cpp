/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int solveRec(int index, int prev, int &m, int &n, vector<int> &arr, vector<vector<int>> &dp)
{
    if (index >= n)
        return 1;
    if (dp[index][prev + 1] != -1)
        return dp[index][prev + 1];

    int ans = 0;
    if (arr[index] != 0)
    {
        // prev ==-1
        if (prev == -1)
            ans = (ans % mod + solveRec(index + 1, arr[index], m, n, arr, dp) % mod) % mod;
        // prev!=-1
        else
        {
            if (abs(prev - arr[index]) > 1)
                return 0;
            ans = (ans % mod + solveRec(index + 1, arr[index], m, n, arr, dp) % mod) % mod;
        }
    }
    else
    {
        if (prev == -1)
        {
            for (int pos = 1; pos <= m; pos++)
            {
                ans = (ans % mod + solveRec(index + 1, pos, m, n, arr, dp) % mod) % mod;
            }
        }
        else
        {
            if (prev + 1 <= m)
                ans = (ans % mod + solveRec(index + 1, prev + 1, m, n, arr, dp) % mod) % mod;
            if (prev - 1 >= 1)
                ans = (ans % mod + solveRec(index + 1, prev - 1, m, n, arr, dp) % mod) % mod;
            ans = (ans % mod + solveRec(index + 1, prev, m, n, arr, dp) % mod) % mod;
        }
        // for (int i = 1; i <= m; i++)
        // {
        //     bool pos = true;
        //     if (index > 0 && arr[index - 1] != 0 && abs(arr[index - 1] - i) > 1)
        //         pos = false;
        //     if (index < n - 1 && arr[index + 1] != 0 && abs(arr[index + 1] - i) > 1)
        //         pos = false;

        //     if (pos)
        //         ans = (ans % mod + solveRec(index + 1, m, n, arr, dp) % mod) % mod;
        // }
    }

    return dp[index][prev + 1] = ans;
}

int solve()
{

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n + 1, vector<int>(102, -1));
    cout << solveRec(0, -1, m, n, arr, dp);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // cin>>t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}