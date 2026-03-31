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
vector<pair<ll, int>> lSegTree; // left +1 -> minval, minind
vector<pair<ll, int>> rSegTree; // right +1 -> minval, minind

void buildLSegTree(int index, int low, int high)
{
    if (low == high)
    {
        lSegTree[index] = {arr[low], low};
        return;
    }

    int mid = low + (high - low) / 2;
    buildLSegTree(2 * index + 1, low, mid);
    buildLSegTree(2 * index + 2, mid + 1, high);

    ll dist = lSegTree[2 * index + 2].second - lSegTree[2 * index + 1].second;
    if (lSegTree[2 * index + 1].first + dist < lSegTree[2 * index + 2].first)
    {
        lSegTree[index] = lSegTree[2 * index + 1];
    }
    else
    {
        lSegTree[index] = lSegTree[2 * index + 2];
    }
}

void buildRSegTree(int index, int low, int high)
{
    if (low == high)
    {
        rSegTree[index] = {arr[low], low};
        return;
    }

    int mid = low + (high - low) / 2;
    buildRSegTree(2 * index + 1, low, mid);
    buildRSegTree(2 * index + 2, mid + 1, high);

    ll dist = rSegTree[2 * index + 2].second - rSegTree[2 * index + 1].second;
    if (rSegTree[2 * index + 2].first + dist < rSegTree[2 * index + 1].first)
    {
        rSegTree[index] = rSegTree[2 * index + 2];
    }
    else
    {
        rSegTree[index] = rSegTree[2 * index + 1];
    }
}

void updateLSegTree(int index, int low, int high, int k)
{
    if (k < low || high < k)
    {
        return;
    }
    if (low == high)
    {
        lSegTree[index] = {arr[low], low};
        return;
    }

    int mid = low + (high - low) / 2;
    updateLSegTree(2 * index + 1, low, mid, k);
    updateLSegTree(2 * index + 2, mid + 1, high, k);

    ll dist = lSegTree[2 * index + 2].second - lSegTree[2 * index + 1].second;
    if (lSegTree[2 * index + 1].first + dist < lSegTree[2 * index + 2].first)
    {
        lSegTree[index] = lSegTree[2 * index + 1];
    }
    else
    {
        lSegTree[index] = lSegTree[2 * index + 2];
    }
}

void updateRSegTree(int index, int low, int high, int k)
{
    if (k < low || high < k)
    {
        return;
    }
    if (low == high)
    {
        rSegTree[index] = {arr[low], low};
        return;
    }

    int mid = low + (high - low) / 2;
    updateRSegTree(2 * index + 1, low, mid, k);
    updateRSegTree(2 * index + 2, mid + 1, high, k);

    ll dist = rSegTree[2 * index + 2].second - rSegTree[2 * index + 1].second;
    if (rSegTree[2 * index + 2].first + dist < rSegTree[2 * index + 1].first)
    {
        rSegTree[index] = rSegTree[2 * index + 2];
    }
    else
    {
        rSegTree[index] = rSegTree[2 * index + 1];
    }
}

pair<ll, int> queryLSegTree(int index, int low, int high, int lRange, int hRange)
{
    if (hRange < low || high < lRange)
    {
        return {LLONG_MAX, -1};
    }
    if (lRange <= low && high <= hRange)
    {
        return lSegTree[index];
    }

    int mid = low + (high - low) / 2;
    pair<ll, int> minLeft = queryLSegTree(2 * index + 1, low, mid, lRange, hRange);
    pair<ll, int> minRight = queryLSegTree(2 * index + 2, mid + 1, high, lRange, hRange);

    if (minLeft.first == LLONG_MAX)
    {
        return minRight;
    }
    else if (minRight.first == LLONG_MAX)
    {
        return minLeft;
    }
    else
    {
        ll dist = minRight.second - minLeft.second;
        if (minLeft.first + dist < minRight.first)
        {
            return minLeft;
        }
        else
        {
            return minRight;
        }
    }
}

pair<ll, int> queryRSegTree(int index, int low, int high, int lRange, int hRange)
{
    if (hRange < low || high < lRange)
    {
        return {LLONG_MAX, -1};
    }
    if (lRange <= low && high <= hRange)
    {
        return rSegTree[index];
    }

    int mid = low + (high - low) / 2;
    pair<ll, int> minLeft = queryRSegTree(2 * index + 1, low, mid, lRange, hRange);
    pair<ll, int> minRight = queryRSegTree(2 * index + 2, mid + 1, high, lRange, hRange);

    if (minLeft.first == LLONG_MAX)
    {
        return minRight;
    }
    else if (minRight.first == LLONG_MAX)
    {
        return minLeft;
    }
    else
    {
        ll dist = minRight.second - minLeft.second;
        if (minRight.first + dist < minLeft.first)
        {
            return minRight;
        }
        else
        {
            return minLeft;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    lSegTree.resize(4 * n);
    buildLSegTree(0, 0, n - 1);
    rSegTree.resize(4 * n);
    buildRSegTree(0, 0, n - 1);

    vector<ll> ans;
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int k, x;
            cin >> k >> x;
            k--;
            arr[k] = x;
            updateLSegTree(0, 0, n - 1, k);
            updateRSegTree(0, 0, n - 1, k);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            pair<ll, int> minLeft = queryLSegTree(0, 0, n - 1, 0, k);
            pair<ll, int> minRight = queryRSegTree(0, 0, n - 1, k, n - 1);
            ll minAns = min(minLeft.first + 1ll * (k - minLeft.second),
                            minRight.first + 1ll * (minRight.second - k));
            ans.push_back(minAns);
        }
    }

    for (auto &i : ans)
    {
        cout << i << endl;
    }

    return 0;
}