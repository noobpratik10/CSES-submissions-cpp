#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll pSum = 0;
    map<ll, ll> cnt;
    cnt[0] = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        pSum += arr[i];
        ll rem = ((pSum % n) + n) % n;
        ;
        ans += cnt[rem];
        cnt[rem]++;
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