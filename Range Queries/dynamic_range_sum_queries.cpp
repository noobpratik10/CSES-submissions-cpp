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

void updateSegTree(int index, int low, int high, int k, int u)
{
    if (k < low || high < k)
    {
        return;
    }
    if (low == high)
    {
        segTree[index] = u;
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
            updateSegTree(0, 0, n - 1, k, u);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            ans.push_back(querySegTree(0, 0, n - 1, a, b));
        }
    }

    for (auto &i : ans)
    {
        cout << i << endl;
    }

    return 0;
}