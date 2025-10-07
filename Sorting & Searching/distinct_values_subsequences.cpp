#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    long long ans = 1;
    for (auto i : cnt)
    {
        ans = ((ans % mod) * ((i.second + 1) % mod)) % mod;
    }
    cout << (ans - 1 + mod) % mod << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
