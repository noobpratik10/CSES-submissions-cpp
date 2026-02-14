/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

pair<ll, ll> getChildDist(int cur, int par, vector<vector<ll>> &distAndNodes,
                          vector<vector<int>> &adj)
{

    // get and store all children dist. & nodes.
    for (auto &child : adj[cur])
    {
        if (child == par)
        {
            continue;
        }
        pair<ll, ll> curChildAns = getChildDist(child, cur, distAndNodes, adj);
        distAndNodes[cur][0] += curChildAns.first;
        distAndNodes[cur][1] += curChildAns.second;
    }

    // inclde cur node in ans to send to par.
    pair<ll, ll> curAns = {distAndNodes[cur][0], distAndNodes[cur][1]};
    curAns.first += distAndNodes[cur][1] + 1; // inc. child dist by 1+ cur. dist.1
    curAns.second += 1;                       // incl. cur node
    return curAns;
}

void getParDist(int cur, int par, int &totalNodes, vector<vector<ll>> &distAndNodes, vector<vector<int>> &adj)
{
    // update first for cur node
    if (par != -1)
    {
        distAndNodes[cur][0] += distAndNodes[par][0] - distAndNodes[cur][0] -
                                distAndNodes[cur][1] - 1 + totalNodes - distAndNodes[cur][1] - 1;
    }

    // then update for the children
    for (auto &child : adj[cur])
    {
        if (child == par)
        {
            continue;
        }
        getParDist(child, cur, totalNodes, distAndNodes, adj);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // get total dist children & no. of children for ever node
    vector<vector<ll>> distAndNodes(n, vector<ll>(2, 0)); // dist node
    getChildDist(0, -1, distAndNodes, adj);

    // update the par (and its subtree) distance to the ans
    getParDist(0, -1, n, distAndNodes, adj);

    // print ans
    for (auto &i : distAndNodes)
    {
        cout << i[0] << " ";
    }
    cout << endl;

    return 0;
}