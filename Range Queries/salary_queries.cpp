/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// Trick:- use co-ordinate compression -> to reduce time & space
//           complexity of seg tree stored
#define ll long long
vector<int> cordinate;
vector<ll> cordinateCnt;
vector<int> arr;
vector<vector<int>> queries;
vector<ll> segTree;

void buildSegTree(int index, int low, int high)
{
    if (low == high)
    {
        segTree[index] = cordinateCnt[low];
        return;
    }

    int mid = low + (high - low) / 2;
    buildSegTree(2 * index + 1, low, mid);
    buildSegTree(2 * index + 2, mid + 1, high);
    segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
}

void updateSegTree(int index, int low, int high, int pos)
{
    if (pos < low || high < pos)
    {
        return;
    }
    if (low == high)
    {
        segTree[index] = cordinateCnt[low];
        return;
    }

    int mid = low + (high - low) / 2;
    updateSegTree(2 * index + 1, low, mid, pos);
    updateSegTree(2 * index + 2, mid + 1, high, pos);
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
    ll lCnt = querySegTree(2 * index + 1, low, mid, lRange, hRange);
    ll rCnt = querySegTree(2 * index + 2, mid + 1, high, lRange, hRange);
    return lCnt + rCnt;
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
        cordinate.push_back(arr[i]);
    }

    queries.resize(q);
    for (int i = 0; i < q; i++)
    {
        char ch;
        cin >> ch;
        int t = (ch == '?') ? 1 : 2;
        int x, y;
        cin >> x >> y;
        if (t == 1)
        {
            cordinate.push_back(x);
        }
        cordinate.push_back(y);
        queries[i] = {t, x, y};
    }

    sort(cordinate.begin(), cordinate.end());
    cordinate.erase(unique(cordinate.begin(), cordinate.end()), cordinate.end());

    int cordSize = cordinate.size();
    cordinateCnt.resize(cordSize, 0);
    for (int i = 0; i < n; i++)
    {
        int cordI = lower_bound(cordinate.begin(), cordinate.end(), arr[i]) - cordinate.begin();
        cordinateCnt[cordI]++;
    }

    segTree.resize(4 * cordSize);
    buildSegTree(0, 0, cordSize - 1);

    vector<ll> ans;
    for (int i = 0; i < q; i++)
    {
        if (queries[i][0] == 1)
        {
            int a = queries[i][1];
            int b = queries[i][2];
            int aCord = lower_bound(cordinate.begin(), cordinate.end(), a) - cordinate.begin();
            int bCord = lower_bound(cordinate.begin(), cordinate.end(), b) - cordinate.begin();
            ll curAns = querySegTree(0, 0, cordSize - 1, aCord, bCord);
            ans.push_back(curAns);
        }
        else
        {
            int k = queries[i][1];
            int x = queries[i][2];
            int kArr = arr[k - 1];
            int kCord = lower_bound(cordinate.begin(), cordinate.end(), kArr) - cordinate.begin();
            cordinateCnt[kCord]--;
            updateSegTree(0, 0, cordSize - 1, kCord);
            int xCord = lower_bound(cordinate.begin(), cordinate.end(), x) - cordinate.begin();
            cordinateCnt[xCord]++;
            updateSegTree(0, 0, cordSize - 1, xCord);
            arr[k - 1] = x;
        }
    }

    for (auto &i : ans)
    {
        cout << i << endl;
    }

    return 0;
}