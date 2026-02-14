#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

bool isPos(ll mid, int n, int k, vector<int> &arr)
{
    int cnt = 1;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;

        if (sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else
        {
            cnt++;
            sum = arr[i];
        }
    }
    return (cnt <= k);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // sort(arr.begin(),arr.end());
    ll low = 1;
    ll high = accumulate(arr.begin(), arr.end(), 0ll);
    ll ans = high;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (isPos(mid, n, k, arr))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
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