/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;
vector<ll> segTree;

ll query(int ind, int l, int r, int ql, int qr)
{
    if (qr < l || ql > r)
    {
        return 0ll;
    }
    if (ql <= l && qr >= r)
    {
        return segTree[ind];
    }

    int mid = l + (r - l) / 2;
    ll leftAns = query(2 * ind + 1, l, mid, ql, qr);
    ll rightAns = query(2 * ind + 2, mid + 1, r, ql, qr);
    return (leftAns + rightAns) % mod;
}

ll update(int ind, int l, int r, int pos, ll val)
{
    if (pos < l || pos > r)
        return segTree[ind];
    if (l == r)
        return segTree[ind] += val;

    int mid = l + (r - l) / 2;
    ll leftAns = update(2 * ind + 1, l, mid, pos, val);
    ll rightAns = update(2 * ind + 2, mid + 1, r, pos, val);
    return segTree[ind] = (leftAns + rightAns) % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> allVals(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        allVals[i] = arr[i];
    }
    // co-ordinate compression
    sort(allVals.begin(), allVals.end());
    allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());

    auto getId = [&](int x)
    {
        return int(lower_bound(allVals.begin(), allVals.end(), x) - allVals.begin());
    };

    // segTree+answer
    int MAX_ID = allVals.size();
    segTree.resize(4 * MAX_ID, 0);

    for (int i = 0; i < n; i++)
    {
        int id = getId(arr[i]);
        ll cnt = query(0, 0, MAX_ID - 1, 0, id - 1) % mod;
        cnt = (cnt + 1) % mod;
        update(0, 0, MAX_ID - 1, id, cnt);
    }

    // getans
    cout << query(0, 0, MAX_ID - 1, 0, MAX_ID - 1) % mod << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    // cin>>t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}