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

#define ll long long
ll ans = 0;
vector<vector<int>> adj;
vector<bool> processed; // stores all the processed centroids
vector<int> totalCnt;   // cnt(i)[d] = sum of the cnt of nodes at depth d from chil 0 till i of cur node
vector<int> subTreeNodeCnt;
vector<int> cnt;

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

void calcCnt(int cur, int par, int depth, int &subTreeDepth, int k2)
{
    if (depth > k2)
    {
        return;
    }

    cnt[depth]++; // inc cur node in cnt
    subTreeDepth = max(subTreeDepth, depth);

    for (auto &child : adj[cur])
    {
        if (!processed[child] && child != par)
        {
            calcCnt(child, cur, depth + 1, subTreeDepth, k2);
        }
    }
}

void centroidDecomposition(int cur, int k1, int k2)
{
    int centroid = getCentroid(cur, -1, getSubTreeNodeCnt(cur, -1));
    processed[centroid] = true;
    totalCnt[0] = 1; // no of node at depth 0 > itself
    int maxDepth = 0;
    // centroid itself is only counted if paths of depth 1 are valid
    ll partialSumInit = (k1 == 1 ? 1ll : 0ll);

    for (auto &child : adj[centroid])
    {
        if (!processed[child])
        {
            // fill the cnt with no of nodes at depth d
            int subTreeDepth = 0;
            calcCnt(child, centroid, 1, subTreeDepth, k2);

            // get the partialsum & ans acc. to totalCnt & cnt
            ll partialSum = partialSumInit;
            for (int depth = 1; depth <= subTreeDepth; depth++)
            {
                ans += partialSum * cnt[depth];

                // update the partial sum
                int dRemove = k2 - depth;
                if (dRemove >= 0)
                {
                    partialSum -= totalCnt[dRemove];
                }
                int dAdd = k1 - (depth + 1);
                if (dAdd >= 0)
                {
                    partialSum += totalCnt[dAdd];
                }
            }

            // update partial sum init from cur subtree for
            //  depth=1 of upcoming subtrees
            for (int depth = k1 - 1; depth <= k2 - 1 && depth <= subTreeDepth; depth++)
            {
                partialSumInit += cnt[depth];
            }

            // update the total cnt for upcoming subtrees
            for (int depth = 1; depth <= subTreeDepth; depth++)
            {
                totalCnt[depth] += cnt[depth];
            }

            // update the maxdepth for refilling the totalCnt
            maxDepth = max(maxDepth, subTreeDepth);

            // refill the cnt for next subtree
            fill(cnt.begin(), cnt.begin() + subTreeDepth + 1, 0);
        }
    }

    // Refill the totalCnt for next centroid
    //  use fill and not assign to incr. efficiency and reduce TC
    fill(totalCnt.begin(), totalCnt.begin() + maxDepth + 1, 0); // reset cnt for new centroid

    for (auto &child : adj[centroid])
    {
        if (!processed[child])
        {
            centroidDecomposition(child, k1, k2);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k1, k2;
    cin >> n >> k1 >> k2;
    if (k1 > k2)
    {
        swap(k1, k2);
    }

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
    totalCnt.assign(k2 + 1, 0);
    cnt.assign(k2 + 1, 0);
    centroidDecomposition(0, k1, k2);
    cout << ans << endl;

    return 0;
}
