#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<ll, vector<vector<int>>> mp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            mp[1ll * (arr[i] + arr[j])].push_back({i, j});
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll search = x - (arr[i] + arr[j]);
            for (auto v : mp[search])
            {
                if (i != v[0] && i != v[1] && j != v[0] && j != v[1])
                {
                    cout << i + 1 << " " << j + 1 << " " << v[0] + 1 << " " << v[1] + 1 << endl;
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
