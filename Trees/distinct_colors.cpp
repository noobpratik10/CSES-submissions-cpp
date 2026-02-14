/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> colors;
vector<int> subTreeColorCnt;

set<int> dfs(int cur, int par)
{

    set<int> curColors = {colors[cur]};
    for (auto &child : adj[cur])
    {
        if (child == par)
        {
            continue;
        }
        set<int> childColors = dfs(child, cur);

        if (curColors.size() < childColors.size())
        {
            swap(curColors, childColors);
        }

        for (auto &c : childColors)
        {
            curColors.insert(c);
        }
    }

    subTreeColorCnt[cur] = curColors.size();
    return curColors;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    colors.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> colors[i];
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

    subTreeColorCnt.resize(n);
    dfs(0, -1);

    for (auto &i : subTreeColorCnt)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}