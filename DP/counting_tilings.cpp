#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

void generateTransitions(int mask, int newMask, int row, int n, vector<vector<int>> &transitions)
{
    if (row >= n)
    {
        transitions[mask].push_back(newMask);
        return;
    }

    if (mask & (1 << row))
    {
        generateTransitions(mask, newMask, row + 1, n, transitions);
    }
    else
    {
        if (row + 1 < n && !(mask & (1 << (row + 1))))
        {
            // vertical domino
            generateTransitions(mask, newMask, row + 2, n, transitions);
        }
        // horizontal domino
        generateTransitions(mask, newMask | (1 << row), row + 1, n, transitions);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int totalMask = 1 << n;

    vector<vector<int>> transitions(totalMask);
    for (int mask = 0; mask < totalMask; mask++)
    {
        generateTransitions(mask, 0, 0, n, transitions);
    }

    vector<ll> prev(totalMask, 0);
    prev[0] = 1;

    for (int col = 0; col < m; col++)
    {
        vector<ll> curr(totalMask, 0);
        for (int mask = 0; mask < totalMask; mask++)
        {
            for (int newMask : transitions[mask])
            {
                curr[newMask] = (curr[newMask] + prev[mask]) % mod;
            }
        }
        prev = curr;
    }

    cout << prev[0] % mod << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
