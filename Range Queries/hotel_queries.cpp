/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> segTree;

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
    segTree[index] = max(segTree[2 * index + 1], segTree[2 * index + 2]);
}

int querySegTree(int index, int low, int high, int lRange, int hRange)
{
    if (hRange < low || high < lRange)
    {
        return 0;
    }
    if (lRange <= low && high <= hRange)
    {
        return segTree[index];
    }

    int mid = low + (high - low) / 2;
    int lMax = querySegTree(2 * index + 1, low, mid, lRange, hRange);
    int rMax = querySegTree(2 * index + 2, mid + 1, high, lRange, hRange);
    return max(lMax, rMax);
}

void updateSegTree(int index, int low, int high, int pos, int val)
{
    if (pos < low || high < pos)
    {
        return;
    }
    if (low == high)
    {
        segTree[index] -= val;
        return;
    }

    int mid = low + (high - low) / 2;
    updateSegTree(2 * index + 1, low, mid, pos, val);
    updateSegTree(2 * index + 2, mid + 1, high, pos, val);
    segTree[index] = max(segTree[2 * index + 1], segTree[2 * index + 2]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int segSize = 4 * n;
    segTree.resize(segSize);
    buildSegTree(0, 0, n - 1);

    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;

        int low = 0;
        int high = n - 1;
        int curAns = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int maxVal = querySegTree(0, 0, n - 1, 0, mid);
            if (maxVal >= q)
            {
                curAns = min(curAns, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (curAns < n)
        {
            updateSegTree(0, 0, n - 1, curAns, q);
            ans.push_back(curAns + 1);
        }
        else
        {
            ans.push_back(0);
        }
    }

    for (auto &i : ans)
    {
        cout << i << " ";
    }

    return 0;
}