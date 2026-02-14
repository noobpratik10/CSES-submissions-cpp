#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

ll subarrSum(int x, int n, vector<int> &arr)
{
    int i = 0, j = 0;
    ll cnt = 0;
    ll curSum = 0;
    while (j < n)
    {
        curSum += arr[j];
        while (i < j && curSum > 1ll * x)
        {
            curSum -= arr[i];
            i++;
        }
        if (curSum <= 1ll * x)
        {
            cnt += (j - i + 1);
        }
        j++;
    }
    return cnt;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << subarrSum(x, n, arr) - subarrSum(x - 1, n, arr) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}
