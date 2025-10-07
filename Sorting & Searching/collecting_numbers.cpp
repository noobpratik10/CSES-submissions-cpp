#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // store position of each number
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        pos[arr[i]] = i;
    }

    int cnt = 1; // at least one round
    for (int i = 2; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
        {
            cnt++; // need new round
        }
    }

    cout << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
