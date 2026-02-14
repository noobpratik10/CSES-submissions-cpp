/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

pair<int, long long> solveRec(int state, int &x, int &n, vector<int> &arr,
                              vector<pair<int, long long>> &dp)
{
    if (state <= 0)
    {
        return {1, 0};
    }
    if (dp[state].first != -1)
    {
        return dp[state];
    }
    pair<int, long long> bestSoln = {n + 1, 0};
    for (int i = 0; i < n; i++)
    {
        if (state & (1 << i))
        {
            int nextState = state ^ (1 << i);
            auto [rides, curWt] = solveRec(nextState, x, n, arr, dp);
            if (curWt + arr[i] <= x)
            {
                bestSoln = min(bestSoln, {rides, curWt + arr[i]});
            }
            else
            {
                bestSoln = min(bestSoln, {rides + 1, arr[i]});
            }
        }
    }
    return dp[state] = bestSoln;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<pair<int, long long>> dp(1 << n, {-1, -1});
    cout << solveRec((1 << n) - 1, x, n, arr, dp).first << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    // cin>>t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}