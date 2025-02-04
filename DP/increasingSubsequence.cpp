#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll n, vector<ll> &arr)
{
    vector<ll> subLen;
    for (ll i = 0; i < n; i++)
    {
        if (subLen.empty() || subLen.back() < arr[i])
            subLen.push_back(arr[i]);
        else
        {
            auto it = lower_bound(subLen.begin(), subLen.end(), arr[i]);
            *it = arr[i];
        }
    }
    return 1LL * (subLen.size());
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    cout << solve(n, arr) << endl;
    return 0;
}