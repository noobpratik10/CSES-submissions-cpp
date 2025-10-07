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
    int n, a, b;
    cin >> n >> a >> b;

    vector<bool> visa(n + 1, 0);
    vector<bool> visb(n + 1, 0);
    int curA = 0, curB = 0;
    bool pos = false;
    vector<vector<int>> ans;
    while (n--)
    {
        if (a--)
        {
            int start = -1;
            while (visa[curA] || curA <= curB)
            {
                if (start == -1)
                    start = curA;
                else if (start == curA)
                    break;
                curA = (curA + 1) % (n + 1);
            }
            if ()
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}