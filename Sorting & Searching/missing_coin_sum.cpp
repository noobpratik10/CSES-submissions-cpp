#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    long long reachable = 0;
    for (auto i : arr)
    {
        if (i <= reachable + 1)
        {
            reachable += i;
        }
        else
        {
            cout << reachable + 1 << endl;
            return;
        }
    }
    cout << reachable + 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
