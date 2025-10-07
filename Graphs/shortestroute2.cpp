/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u - 1][v - 1] = min(dist[u - 1][v - 1], (long long)w);
        dist[v - 1][u - 1] = min(dist[v - 1][u - 1], (long long)w);
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (dist[i][j] != LLONG_MAX && dist[j][k] != LLONG_MAX)
                {
                    dist[i][k] = min(dist[i][k], dist[i][j] + dist[j][k]);
                }
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (LLONG_MAX > min(dist[u - 1][v - 1], dist[v - 1][u - 1]))
            cout << min(dist[u - 1][v - 1], dist[v - 1][u - 1]) << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}