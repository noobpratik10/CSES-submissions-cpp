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
vector<ll> segTree;

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
    ll lSum = querySegTree(2 * index + 1, low, mid, lRange, hRange);
    ll rSum = querySegTree(2 * index + 2, mid + 1, high, lRange, hRange);
    return lSum + rSum;
}

void updateSegTree(int index, int low, int high, int pos)
{
    if (pos < low || high < pos)
    {
        return;
    }
    if (low == high)
    {
        segTree[index]++;
        return;
    }

    int mid = low + (high - low) / 2;
    updateSegTree(2 * index + 1, low, mid, pos);
    updateSegTree(2 * index + 2, mid + 1, high, pos);
    segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    segTree.resize(4 * n, 0ll);

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int target;
        cin >> target;
        target--;

        int low = 0;
        int high = n - 1;
        int actualTarget = n;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int removedCnt = querySegTree(0, 0, n - 1, 0, mid);
            if (mid - removedCnt < target)
            {
                low = mid + 1;
            }
            else
            {
                actualTarget = min(actualTarget, mid);
                high = mid - 1;
            }
        }

        ans.push_back(arr[actualTarget]);
        updateSegTree(0, 0, n - 1, actualTarget);
    }

    for (auto &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}