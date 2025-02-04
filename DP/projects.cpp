#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> p(n);

    for (ll i = 0; i < n; i++)
    {
        ll a, b, c; // end start reward
        cin >> a >> b >> c;
        p[i] = {b, a, c};
    }

    sort(p.begin(), p.end());
    map<ll, ll> dp;
    dp[0] = 0;
    ll bestSoFar = 0;
    for (auto i : p)
    {
        ll end = i[0], start = i[1], reward = i[2];
        auto it = dp.lower_bound(start);
        it--;
        ll totalReward = it->second + reward;
        bestSoFar = max(bestSoFar, totalReward);
        dp[end] = bestSoFar;
    }
    cout << bestSoFar << endl;
    return 0;
}