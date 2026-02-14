/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int solveRec(int i, int j, int &n, int &m, vector<int> &arr1, vector<int> &arr2)
{
    if (i >= n || j >= m)
    {
        return 0;
    }
    int ans = 0;
    if (arr1[i] == arr2[j])
    {
        ans = max(ans, 1 + solveRec(i + 1, j + 1, n, m, arr1, arr2));
    }
    ans = max(ans, 0 + solveRec(i, j + 1, n, m, arr1, arr2));
    ans = max(ans, 0 + solveRec(i + 1, j, n, m, arr1, arr2));
    ans = max(ans, 0 + solveRec(i + 1, j + 1, n, m, arr1, arr2));
    return ans;
}

void solveTab(int &n, int &m, vector<int> &arr1, vector<int> &arr2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;
            if (arr1[i] == arr2[j])
            {
                ans = max(ans, 1 + dp[i + 1][j + 1]);
            }
            ans = max(ans, 0 + dp[i][j + 1]);
            ans = max(ans, 0 + dp[i + 1][j]);
            ans = max(ans, 0 + dp[i + 1][j + 1]);
            dp[i][j] = ans;
        }
    }

    vector<int> lcs;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            lcs.push_back(arr1[i]);
            i++;
            j++;
        }
        else
        {
            if (dp[i + 1][j] >= dp[i][j + 1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }

    cout << dp[0][0] << endl;
    for (auto l : lcs)
    {
        cout << l << " ";
    }
    cout << endl;
}

void solve()
{

    int n, m;
    cin >> n >> m;

    vector<int> arr1(n);
    vector<int> arr2(m);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    // cout<<solveRec(0,0,n,m,arr1,arr2)<<endl;
    solveTab(n, m, arr1, arr2);
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