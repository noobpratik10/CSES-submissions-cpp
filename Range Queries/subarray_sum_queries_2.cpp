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
    ll sum, maxSum, prefix, suffix;

    Node(ll sum = 0, ll maxSum = 0, ll prefix = 0, ll suffix = 0)
    {
        this->sum = sum;
        this->maxSum = maxSum;
        this->prefix = prefix;
        this->suffix = suffix;
    }
};

vector<int> arr;
vector<Node> segTree;

void merge(Node &cur, Node &left, Node &right)
{
    cur.sum = left.sum + right.sum;

    if (left.prefix >= left.sum + right.prefix)
    {
        cur.prefix = left.prefix;
    }
    else
    {
        cur.prefix = left.sum + right.prefix;
    }
    if (right.suffix >= right.sum + left.suffix)
    {
        cur.suffix = right.suffix;
    }
    else
    {
        cur.suffix = right.sum + left.suffix;
    }

    cur.maxSum = max({left.maxSum,
                      right.maxSum,
                      left.suffix + right.prefix});
}

void buildSegTree(int index, int low, int high)
{
    if (low == high)
    {
        segTree[index] = Node(arr[low], arr[low], arr[low], arr[low]);
        return;
    }

    int mid = low + (high - low) / 2;
    buildSegTree(2 * index + 1, low, mid);
    buildSegTree(2 * index + 2, mid + 1, high);
    segTree[index] = Node(0LL, 0LL, 0LL, 0LL);
    merge(segTree[index], segTree[2 * index + 1], segTree[2 * index + 2]);
}

Node querySegTree(int index, int low, int high, int lRange, int hRange)
{
    if (hRange < low || high < lRange)
    {
        return Node(0LL, 0LL, 0LL, 0LL);
    }
    if (lRange <= low && high <= hRange)
    {
        return segTree[index];
    }

    int mid = low + (high - low) / 2;
    Node lAns = querySegTree(2 * index + 1, low, mid, lRange, hRange);
    Node rAns = querySegTree(2 * index + 2, mid + 1, high, lRange, hRange);

    Node curAns = Node(0LL, 0LL, 0LL, 0LL);
    merge(curAns, lAns, rAns);
    return curAns;
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

    segTree.resize(4 * n);
    buildSegTree(0, 0, n - 1);

    vector<ll> ans;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        Node curAns = querySegTree(0, 0, n - 1, a, b);
        ans.push_back(max(0ll, curAns.maxSum));
    }

    for (auto &i : ans)
    {
        cout << i << endl;
    }

    return 0;
}