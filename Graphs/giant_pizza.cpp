/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> adjRev;
stack<int> st;
vector<bool> visited;
vector<int> component;
vector<bool> assignment;
int n, m;

int negateVar(int x)
{
    return (x < m) ? (x + m) : (x - m);
}

void addClause(int x, int y)
{
    adj[negateVar(x)].push_back(y);
    adj[negateVar(y)].push_back(x);
    adjRev[y].push_back(negateVar(x));
    adjRev[x].push_back(negateVar(y));
}

void dfs1(int cur)
{
    visited[cur] = true;
    for (auto &nbr : adj[cur])
    {
        if (!visited[nbr])
        {
            dfs1(nbr);
        }
    }
    st.push(cur);
}

void dfs2(int cur, int comp)
{
    component[cur] = comp;
    for (auto &nbr : adjRev[cur])
    {
        if (component[nbr] == -1)
        {
            dfs2(nbr, comp);
        }
    }
}

void solve()
{
    cin >> n >> m;
    adj.resize(2 * m);
    adjRev.resize(2 * m);
    visited.resize(2 * m);
    component.resize(2 * m, -1);
    assignment.resize(m);

    // build implication graph
    for (int i = 0; i < n; i++)
    {
        char a, c;
        int b, d;
        cin >> a >> b >> c >> d;
        b--, d--;
        if (a == '-')
            b = negateVar(b);
        if (c == '-')
            d = negateVar(d);
        addClause(b, d);
    }

    // get toposort
    for (int i = 0; i < 2 * m; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }

    // get components
    int curComp = 0;
    while (!st.empty())
    {
        auto cur = st.top();
        st.pop();
        if (component[cur] == -1)
        {
            dfs2(cur, curComp);
            curComp++;
        }
    }

    // SCC processing
    for (int i = 0; i < m; i++)
    {
        if (component[i] == component[negateVar(i)])
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        assignment[i] = component[i] > component[negateVar(i)];
    }

    // print ans
    for (int i = 0; i < m; i++)
    {
        cout << (assignment[i] ? "+ " : "- ");
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    // cin>>t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}