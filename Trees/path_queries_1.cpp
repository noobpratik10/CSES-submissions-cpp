/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<int> value;
vector<vector<int>> adj;
vector<int> inTime;
vector<int> outTime;
vector<ll> segTree;
vector<ll> ans;
vector<int> timeVal;

int timer = -1;

void eulerTour(int cur, int par)
{
    timer++;
    inTime[cur] = timer;
    timeVal.push_back(value[cur]); // pos

    for (auto &child : adj[cur])
    {
        if (child == par)
        {
            continue;
        }
        eulerTour(child, cur); // neg
    }

    timer++;
    outTime[cur] = timer;
    timeVal.push_back(-value[cur]);
}

ll buildSegTree(int index, int leftI, int rightI)
{
    if (leftI > rightI)
    {
        return 0ll;
    }
    if (leftI == rightI)
    {
        segTree[index] = timeVal[leftI];
        return segTree[index];
    }

    int mid = leftI + (rightI - leftI) / 2;
    segTree[index] += buildSegTree(2 * index + 1, leftI, mid);
    segTree[index] += buildSegTree(2 * index + 2, mid + 1, rightI);
    return segTree[index];
}

void updateQuerySegTree(int index, int leftI, int rightI, int updatePos, ll newVal)
{
    if (rightI < updatePos || leftI > updatePos)
    {
        return;
    }
    if (leftI == rightI && leftI == updatePos)
    {
        segTree[index] = newVal;
        return;
    }
    int mid = leftI + (rightI - leftI) / 2;
    updateQuerySegTree(2 * index + 1, leftI, mid, updatePos, newVal);
    updateQuerySegTree(2 * index + 2, mid + 1, rightI, updatePos, newVal);
    segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
}

ll sumQuerySegTree(int index, int leftI, int rightI, int lRange, int rRange)
{

    if (rightI < lRange || leftI > rRange)
    {
        return 0ll;
    }
    if (leftI >= lRange && rightI <= rRange)
    {
        return segTree[index];
    }
    ll sum = 0;
    int mid = leftI + (rightI - leftI) / 2;
    sum += sumQuerySegTree(2 * index + 1, leftI, mid, lRange, rRange);
    sum += sumQuerySegTree(2 * index + 2, mid + 1, rightI, lRange, rRange);
    return sum;
}

int main()
{
    // Approach:-
    // 1. we will construct adj list, 0 is the roor, calculate path sum for each node
    // 2. from list we will do euler tour, and get the tree in arr rep. form
    //   this way we will be able to capture a subtree over a index range
    //  Using Optimized Standard Euler Tour:- by using intime, outtime
    // 3. from that arr., we will construct a seg tree, which stores the sum over range
    // of index in that arr
    // 4. Seg tree will have 3 functions:- 1. build seg tree 2. update query 3. sum query
    // 5. for each query, for each node,we will have its left and right index in the the
    //   euler tour arr. , we will use tose to call the update_query and sum_query methods
    //   of seg tree , and return the ans
    // 6. TC:- Euler Tour --> O(n) + SegTree:- Build O(n), Update O(logn), Sum O(logn)

    int n, q;
    cin >> n >> q;
    value.resize(n, 0);
    adj.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    inTime.resize(n, 0);
    outTime.resize(n, 0);
    eulerTour(0, -1);

    int segTreeSize = outTime[0] + 1;
    segTree.resize(4 * segTreeSize + 1, 0);
    buildSegTree(0, 0, segTreeSize - 1);

    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b;
        b--;
        if (a == 1)
        {

            cin >> c;
            updateQuerySegTree(0, 0, segTreeSize - 1, inTime[b], c);   // pos
            updateQuerySegTree(0, 0, segTreeSize - 1, outTime[b], -c); // neg
        }
        else
        {
            // query sum of inTime of root till inTime of target node
            ll curPathSum = sumQuerySegTree(0, 0, segTreeSize - 1, 0, inTime[b]);
            ans.push_back(curPathSum);
        }
    }

    for (auto &i : ans)
    {
        cout << i << endl;
    }

    return 0;
}