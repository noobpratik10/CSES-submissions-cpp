/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<int> height;
vector<vector<int>> adj;

int getLevelPar(int cur, int level)
{
    // we hop each set bit in the level, and that way we go on to find the
    // levelth par
    int levelthPar = cur;
    for (int pos = 0; pos < 20; pos++)
    {
        if ((level >> pos) & 1)
        {
            if (levelthPar == -1)
            {
                break;
            }
            levelthPar = dp[levelthPar][pos];
        }
    }
    return levelthPar;
}

void setHeight(int cur, int h, int par)
{
    height[cur] = h;
    for (auto &child : adj[cur])
    {
        if (child == par)
        {
            continue;
        }
        setHeight(child, h + 1, cur);
    }
}

int getLCA(int a, int b)
{
    // first we will get them on same height
    //  this way we can hop the par properly using dp arr,
    // as their par will be also on the same level after each hop
    if (height[a] < height[b])
    {
        swap(a, b);
    }
    a = getLevelPar(a, height[a] - height[b]);

    if (a == b)
    {
        return a; // one of them is the lca
    }

    // we will try to find 2 pars of each of them , as close as to lca
    //  such that they are diff.
    for (int pos = 19; pos >= 0; pos--)
    {
        if (dp[a][pos] != dp[b][pos])
        {
            a = dp[a][pos];
            b = dp[b][pos];
        }
        // else{
        //     break;  // no break
        //     // if that pos ancestor are equal, then we will check next closer pos
        //     //we will not break
        //     // if travelling from right to left i.e 0 --> 19 then we can break
        // }
    }
    // now the lca will be one level above a or b
    return dp[a][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // get input
    int n, q;
    cin >> n >> q;
    dp.resize(n, vector<int>(20, -1));
    adj.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u); // build adj list
    }

    // assume 0 as root , and then build par list using bfs
    queue<int> qu;
    qu.push(0);
    while (!qu.empty())
    {
        auto cur = qu.front();
        qu.pop();

        for (auto &nbr : adj[cur])
        {
            if (nbr != dp[cur][0] && dp[nbr][0] == -1)
            {                     // nbr is not par
                dp[nbr][0] = cur; // set cur as 2^0=1 level par
                qu.push(nbr);
            }
        }
    }

    // set height of every node, we will need it to get diff nodes on same level
    height.resize(n, 0);
    setHeight(0, 0, -1);

    // preprocess the 2^k till k=20 par
    // we store each 2^kth par for each node
    //  you have to compute one level for all nodes first
    //  then go on to the next level
    for (int k = 0; k < 20; k++)
    {
        for (int i = 0; i < n; i++)
        {
            // this is the recursive relation for binary par
            // 2^kth par of n=2^k-1th par of 2^k-1th par of n
            if (k - 1 >= 0 && dp[i][k - 1] != -1)
            {
                dp[i][k] = dp[dp[i][k - 1]][k - 1];
            }
        }
    }

    // for q queries get the dist b/w the nodes
    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a == 0 || b == 0)
        {
            if (b == 0)
            {
                swap(a, b);
            }
            ans.push_back(height[b]); // dist from root --> b
        }
        else
        {
            // dist[a,b]=dist[a,lca]+dist[lca,b]
            int lca = getLCA(a, b); // lca now will never be -1
            ans.push_back((height[a] + height[b] - 2 * height[lca]));
        }
    }

    for (auto &i : ans)
    {
        cout << i << endl;
    }

    return 0;
}