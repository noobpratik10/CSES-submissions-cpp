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

    // get input
    int n, q;
    cin >> n >> q;
    vector<vector<int>> dp(n, vector<int>(20, -1));
    for (int u = 1; u < n; u++)
    {
        int p;
        cin >> p;
        p--;
        dp[u][0] = p; // 2^0=1 level par
    }

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

    // now process the queries
    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        int cur, level;
        cin >> cur >> level;
        cur--;
        // level--;  -->  //dont decrement the level

        // we hope each set bit in the level, and that way we go on to find the
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
        if (levelthPar != -1)
        {
            levelthPar++;
        }
        ans.push_back(levelthPar);
    }
    for (auto &i : ans)
    {
        cout << i << endl;
    }
    return 0;
}