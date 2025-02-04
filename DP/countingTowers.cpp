#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    // Base cases: At height 1, there's exactly 1 way to have a divisible or non-divisible block
    long long prev0 = 1;
    long long prev1 = 1;
    long long curr0;
    long long curr1;
    // Fill DP table for each height h from 2 to n
    for (int h = 2; h <= n; ++h)
    {
        curr1 = (4 * prev1 + prev0) % MOD; // Transitions for divisible
        curr0 = (2 * prev0 + prev1) % MOD; // Transitions for non-divisible
        prev0 = curr0;
        prev1 = curr1;
    }

    // Total ways for height n is the sum of towers ending with either divisible or non-divisible blocks
    cout << (prev0 + prev1) % MOD << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
