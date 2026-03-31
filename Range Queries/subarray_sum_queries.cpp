/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Node
{
public:
    ll sum, prefix, suffix, maxSum;

    Node(ll sum = 0, ll prefix = 0, ll suffix = 0, ll maxSum = 0)
    {
        this->sum = sum;       // sum of [l,r]
        this->maxSum = maxSum; // maxsum subbarr b/w [l,r]
        this->suffix = suffix; // maxsum subbarr b/w [l,r] that ends at r
        this->prefix = prefix; // maxsum subbarr b/w [l,r] that starts at l
    }
};

vector<int> arr;
vector<Node *> segTree;

void merge(int index)
{
    segTree[index] = new Node();
    segTree[index]->sum = segTree[2 * index + 1]->sum + segTree[2 * index + 2]->sum;
    segTree[index]->prefix = max(segTree[2 * index + 1]->prefix,
                                 segTree[2 * index + 1]->sum + segTree[2 * index + 2]->prefix);
    segTree[index]->suffix = max(segTree[2 * index + 2]->suffix,
                                 segTree[2 * index + 2]->sum + segTree[2 * index + 1]->suffix);
    segTree[index]->maxSum = max({segTree[2 * index + 1]->maxSum, segTree[2 * index + 2]->maxSum,
                                  segTree[2 * index + 1]->suffix + segTree[2 * index + 2]->prefix});
}

void buildSegTree(int index, int low, int high)
{
    if (low == high)
    {
        segTree[index] = new Node(arr[low], arr[low], arr[low], arr[low]);
        return;
    }

    int mid = low + (high - low) / 2;
    buildSegTree(2 * index + 1, low, mid);
    buildSegTree(2 * index + 2, mid + 1, high);
    merge(index);
}

void updateSegTree(int index, int low, int high, int pos, ll val)
{
    if (pos < low || high < pos)
    {
        return;
    }
    if (low == high)
    {
        segTree[index] = new Node(val, val, val, val);
        return;
    }

    int mid = low + (high - low) / 2;
    updateSegTree(2 * index + 1, low, mid, pos, val);
    updateSegTree(2 * index + 2, mid + 1, high, pos, val);
    merge(index);
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

    segTree.resize(4 * n, NULL);
    buildSegTree(0, 0, n - 1);

    vector<ll> ans;
    for (int i = 0; i < q; i++)
    {
        int pos;
        ll val;
        cin >> pos >> val;
        pos--;
        updateSegTree(0, 0, n - 1, pos, val);

        ans.push_back(max(0ll, segTree[0]->maxSum));
    }

    for (auto &i : ans)
    {
        cout << i << endl;
    }

    return 0;
}