#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0, j = 0;
    ll ans = 0;
    map<ll, ll> cnt;
    while (j < n)
    {
        cnt[arr[j]]++;
        while (i < j && cnt.size() > k)
        {
            cnt[arr[i]]--;
            if (cnt[arr[i]] == 0)
                cnt.erase(arr[i]);
            i++;
        }
        if (cnt.size() <= k)
        {
            ans += (j - i + 1);
        }
        j++;
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