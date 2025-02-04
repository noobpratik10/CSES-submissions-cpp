#include <bits/stdc++.h>
using namespace std;

int solveRec(int n, vector<int> &dp)
{
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int ans = INT_MAX;
    int temp = n;
    while (temp > 0)
    {
        int digit = temp % 10;
        temp = temp / 10;
        if (digit > 0)
            ans = min(ans, 1 + solveRec(n - digit, dp));
    }
    return dp[n] = ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << solveRec(n, dp) << endl;
    return 0;
}