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

    multiset<int> mst;
    for (int i = 0; i < n; i++)
    {
        auto it = mst.upper_bound(arr[i]);
        if (it != mst.end())
        {
            mst.erase(it);
            mst.insert(arr[i]);
        }
        else
        {
            mst.insert(arr[i]);
        }
    }
    cout << mst.size() << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
