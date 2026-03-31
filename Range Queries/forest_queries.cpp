/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> grid(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                grid[i][j]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            grid[i][j] += grid[i][j - 1];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] += grid[i - 1][j];
        }
    }

    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        int curAns = 0;
        curAns += grid[r2][c2];
        if (r1 - 1 >= 0)
        {
            curAns -= grid[r1 - 1][c2];
        }
        if (c1 - 1 >= 0)
        {
            curAns -= grid[r2][c1 - 1];
        }
        if (r1 - 1 >= 0 && c1 - 1 >= 0)
        {
            curAns += grid[r1 - 1][c1 - 1];
        }
        ans.push_back(curAns);
    }

    for (auto &i : ans)
    {
        cout << i << endl;
    }

    return 0;
}