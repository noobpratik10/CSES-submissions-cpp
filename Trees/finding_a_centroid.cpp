/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

vector<int> subTreeColorCnt;
vector<map<int, int>> childCnt; // par->child->cnt of nodes in the subtree of that child
vector<int> childCntSum;        // sum of node cnts of subtree of all children

int calcChildCnt(int cur, int par)
{

    for (auto &child : adj[cur])
    {
        if (child == par)
        {
            continue;
        }
        childCnt[cur][child] = calcChildCnt(child, cur);
        childCntSum[cur] += childCnt[cur][child];
    }

    return 1 + childCntSum[cur];
}

int getCentroid(int cur, int par, int &n)
{

    for (auto &child : adj[cur])
    {
        if (child == par)
        {
            continue;
        }

        if (childCnt[cur][child] > n / 2)
        {
            return getCentroid(child, cur, n);
        }
    }

    return cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /*
    Approach:-1
    1. Assume tree rooted at 0, calc. the cnt of nodes in the
        subtree of each child for each node
    2. Then, use dfs search to get o node which satisfies the centroid condition
    */

    int n;
    cin >> n;
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

    childCnt.resize(n);
    childCntSum.resize(n, 0);
    calcChildCnt(0, -1);

    cout << getCentroid(0, -1, n) + 1 << endl;
    return 0;
}