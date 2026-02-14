/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<vector<int>> dir = {{-1, 0}, {0, -1}};

string solveRec(int i, int j, int &n, int &m,
                vector<string> &mat,
                vector<vector<string>> &dp)
{
    if (i == 0 && j == 0)
    {
        return string(1, mat[0][0]); // Convert char to string
    }

    if (!dp[i][j].empty())
        return dp[i][j];

    string ans = "{"; // '{' > 'Z'

    for (auto &d : dir)
    {
        int ni = i + d[0];
        int nj = j + d[1];
        if (ni >= 0 && nj >= 0)
        {
            string cur = solveRec(ni, nj, n, m, mat, dp) + string(1, mat[i][j]);
            ans = min(ans, cur);
        }
    }

    return dp[i][j] = ans;
}

void solve()
{

    int n, m;
    cin >> n;

    vector<string> mat(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }
    m = mat[0].size();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
    cout << solveRec(n - 1, m - 1, n, m, mat, dp) << endl;
    // solveTab(n,m,arr1,arr2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // cin>>t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}