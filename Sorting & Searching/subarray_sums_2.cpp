#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    vector<ll> prefSum(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prefSum[i] = arr[i];
        if (i >= 1)
            prefSum[i] += prefSum[i - 1];
    }
    map<ll, ll> cnt;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll search = prefSum[i] - x;
        if (cnt.find(search) != cnt.end())
        {
            ans += cnt[search];
        }
        if (x == prefSum[i])
        {
            ans++;
        }
        cnt[prefSum[i]]++;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}