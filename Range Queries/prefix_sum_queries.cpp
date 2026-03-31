/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<int> arr;
vector<ll> prefSum;
vector<pair<ll, ll>> segTree; //(max value in range, delta at that point)

void buildSegTree(int index, int low, int high)
{
    if (low == high)
    {
        segTree[index] = {prefSum[low], 0ll};
        return;
    }

    int mid = low + (high - low) / 2;
    buildSegTree(2 * index + 1, low, mid);
    buildSegTree(2 * index + 2, mid + 1, high);
    // delta initially zero
    segTree[index].second = 0ll;
    // get max prefSum in range
    segTree[index].first = max(segTree[2 * index + 1].first + segTree[2 * index + 1].second,
                               segTree[2 * index + 2].first + segTree[2 * index + 2].second);
}

void updateSegTree(int index, int low, int high, int k, ll delta)
{
    if (high < k)
    {
        return;
    }
    if (k <= low)
    {
        segTree[index].second += delta;
        return;
    }
    if (low == high)
    {
        if (k <= low)
        {
            segTree[index].second += delta;
        }
        return;
    }

    int mid = low + (high - low) / 2;
    updateSegTree(2 * index + 1, low, mid, k, delta);
    updateSegTree(2 * index + 2, mid + 1, high, k, delta);
    // update max prefSum in range
    segTree[index].first = max(segTree[2 * index + 1].first + segTree[2 * index + 1].second,
                               segTree[2 * index + 2].first + segTree[2 * index + 2].second);
}

ll querySegTree(int index, int low, int high, int lRange, int hRange)
{
    if (hRange < low || high < lRange)
    {
        return LLONG_MIN;
    }
    if (lRange <= low && high <= hRange)
    {
        return segTree[index].first + segTree[index].second;
    }

    int mid = low + (high - low) / 2;
    ll lMax = querySegTree(2 * index + 1, low, mid, lRange, hRange);
    ll rMax = querySegTree(2 * index + 2, mid + 1, high, lRange, hRange);
    return max(lMax, rMax) + segTree[index].second; // add delta at that point
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    arr.resize(n);
    prefSum.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prefSum[i] = arr[i];
        if (i - 1 >= 0)
        {
            prefSum[i] += prefSum[i - 1];
        }
    }

    segTree.resize(4 * n, {LLONG_MIN, 0ll});
    buildSegTree(0, 0, n - 1);

    vector<ll> ans;
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int k, u;
            cin >> k >> u;
            k--;
            ll delta = u - arr[k];
            arr[k] = u;
            updateSegTree(0, 0, n - 1, k, delta);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if (a > b)
            {
                swap(a, b);
            }
            // get the max prefSum in range --> ([0,a], [0,b])
            ll curAns = querySegTree(0, 0, n - 1, a, b);
            // subs the prefSum till a-1
            if (a - 1 >= 0)
            {
                curAns -= querySegTree(0, 0, n - 1, a - 1, a - 1);
            }
            ans.push_back(max(curAns, 0ll));
        }
    }

    for (auto &i : ans)
    {
        cout << i << endl;
    }

    return 0;
}