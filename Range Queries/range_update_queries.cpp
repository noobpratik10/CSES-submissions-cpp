/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> segTree;
vector<int> arr;

void buildSegTree(int index, int low, int high)
{
    if (low == high)
    {
        segTree[index] = arr[low];
        return;
    }

    int mid = low + (high - low) / 2;
    buildSegTree(2 * index + 1, low, mid);
    buildSegTree(2 * index + 2, mid + 1, high);
    segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
}

void updateSegTree(int index, int low, int high, int k, ll u)
{
    if (k < low || high < k)
    {
        return;
    }
    if (low == high)
    {
        segTree[index] += u;
        return;
    }

    int mid = low + (high - low) / 2;
    updateSegTree(2 * index + 1, low, mid, k, u);
    updateSegTree(2 * index + 2, mid + 1, high, k, u);
    segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
}

ll querySegTree(int index, int low, int high, int lRange, int hRange)
{
    if (hRange < low || high < lRange)
    {
        return 0ll;
    }
    if (lRange <= low && high <= hRange)
    {
        return segTree[index];
    }

    int mid = low + (high - low) / 2;
    return querySegTree(2 * index + 1, low, mid, lRange, hRange) +
           querySegTree(2 * index + 2, mid + 1, high, lRange, hRange);
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

    int segSize = 4 * n;
    segTree.resize(segSize + 1);

    vector<ll> ans;
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            a--;
            b--;
            updateSegTree(0, 0, n - 1, a, u);
            updateSegTree(0, 0, n - 1, b + 1, -u);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            ll updatedVal = querySegTree(0, 0, n - 1, 0, k);
            ans.push_back(arr[k] + updatedVal);
        }
    }

    for (auto &i : ans)
    {
        cout << i << endl;
    }

    return 0;
}
