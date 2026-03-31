/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// Approach:-

// 1. All paths passing through cur node u and terminating at endpoint d depth of
// ith child of some subtree to be of length k should start from some child in diff
// subtree at depth (k-d), so all the paths passing from u, of length k, ending at
// depth d, of child ith of some subtree of u = sum of all nodes at depth k-d
// found till now.

// 2.If we do this for every node, then we will get all the paths of length k, passing through
// every node, which is the ans, but the complexity will be N^2. So to reduce it,
// exery time we choose the u as centroid, so that at max the subtree can be logn deep

// 3.Hence, approx. the overall complexity becomes O(nlogn)

long long ans = 0;
vector<vector<int>> adj;
vector<bool> processed; // stores all the processed centroids
vector<int> cnt;        // cnt(i)[d] = sum of the cnt of nodes at depth d from chil 0 till i of cur node
vector<int> subTreeNodeCnt;

// subtree cnt resets acc. to cur and par everytime the function is called
int getSubTreeNodeCnt(int cur, int par)
{
    subTreeNodeCnt[cur] = 1;
    for (auto &child : adj[cur])
    {
        if (!processed[child] && child != par)
        {
            subTreeNodeCnt[cur] += getSubTreeNodeCnt(child, cur);
        }
    }
    return subTreeNodeCnt[cur];
}

int getCentroid(int cur, int par, int maxSubTreeCnt)
{
    for (auto &child : adj[cur])
    {
        if (!processed[child] && child != par && subTreeNodeCnt[child] > maxSubTreeCnt / 2)
        {
            return getCentroid(child, cur, maxSubTreeCnt);
        }
    }
    return cur;
}

void calcCnt(int cur, int par, bool fillAns, int depth, int k, int &maxDepth)
{
    if (depth > k)
    {
        return;
    }

    if (fillAns)
        ans += cnt[k - depth]; // get ans from prev childs
    else
        cnt[depth]++; // inc cur node in cnt
    maxDepth = max(maxDepth, depth);

    for (auto &child : adj[cur])
    {
        if (!processed[child] && child != par)
        {
            calcCnt(child, cur, fillAns, depth + 1, k, maxDepth);
        }
    }
}

void centroidDecomposition(int cur, int k)
{
    int centroid = getCentroid(cur, -1, getSubTreeNodeCnt(cur, -1));
    processed[centroid] = true;
    cnt[0] = 1; // no of node at depth 0 > itself
    int maxDepth = 1;

    for (auto &child : adj[centroid])
    {
        if (!processed[child])
        {
            calcCnt(child, centroid, true, 1, k, maxDepth);  // calc. paths from all prev child subtrees for this subtree
            calcCnt(child, centroid, false, 1, k, maxDepth); // add nodes from this child subtree to cnt
        }
    }
    // use fill and not assign to incr. efficiency and reduce TC
    fill(cnt.begin(), cnt.begin() + maxDepth + 1, 0); // reset cnt for new centroid

    for (auto &child : adj[centroid])
    {
        if (!processed[child])
        {
            centroidDecomposition(child, k);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    adj.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    processed.resize(n, 0);
    subTreeNodeCnt.resize(n, 0);
    cnt.assign(k + 1, 0);
    centroidDecomposition(0, k);
    cout << ans << endl;

    return 0;
}