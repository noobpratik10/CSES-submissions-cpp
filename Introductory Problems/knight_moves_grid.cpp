/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> ans(n, vector<int>(n, INT_MAX));
    vector<vector<int>> dir = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
    ans[0][0] = 0;
    queue<vector<int>> q;
    q.push({0, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (auto d : dir)
        {
            int ni = cur[0] + d[0];
            int nj = cur[1] + d[1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n)
            {
                if (ans[ni][nj] > ans[cur[0]][cur[1]] + 1)
                {
                    ans[ni][nj] = ans[cur[0]][cur[1]] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}