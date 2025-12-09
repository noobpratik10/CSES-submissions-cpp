/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> Size;
int maxSize = 1;

int findParent(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

void unionBySize(int x, int y)
{
    int parX = findParent(x);
    int parY = findParent(y);

    if (Size[parX] >= Size[parY])
    {
        Size[parX] += Size[parY];
        parent[parY] = parX;
        maxSize = max(maxSize, Size[parX]);
    }
    else
    {
        Size[parY] += Size[parX];
        parent[parX] = parY;
        maxSize = max(maxSize, Size[parY]);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    vector<bool> visited(n, false);
    parent.assign(n, -1);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    Size.assign(n, 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u - 1, v - 1};
    }

    int components = n;
    for (auto &e : edges)
    {
        int parX = findParent(e[0]);
        int parY = findParent(e[1]);
        if (parX != parY)
        {
            unionBySize(e[0], e[1]);
            components--;
        }
        cout << components << " " << maxSize << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}