/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

ll solveRec(ll ind, bool leadingZero, bool prevL, bool prevU, ll prevNum, ll &n, vector<int> &num1, vector<int> &num2,
            vector<vector<vector<vector<vector<ll>>>>> &dp)
{
    if (ind >= n)
    {
        return 1;
    }
    if (dp[ind][prevNum + 1][prevL][prevU][leadingZero] != -1)
    {
        return dp[ind][prevNum + 1][prevL][prevU][leadingZero];
    }

    ll ans = 0;
    for (ll i = 0; i <= 9; i++)
    {
        if (prevL && i < num1[ind])
        {
            continue;
        }
        if (prevU && i > num2[ind])
        {
            continue;
        }
        if (i == prevNum && !leadingZero)
        {
            continue;
        }
        if (i == 0 && (prevNum == -1 || (prevNum == 0 && leadingZero)))
        {
            ans += solveRec(ind + 1, true, prevL && (i == num1[ind]), prevU && (i == num2[ind]), i, n, num1, num2, dp);
        }
        else
        {
            ans += solveRec(ind + 1, false, prevL && (i == num1[ind]), prevU && (i == num2[ind]), i, n, num1, num2, dp);
        }
    }
    return dp[ind][prevNum + 1][prevL][prevU][leadingZero] = ans;
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    vector<int> num1;
    vector<int> num2;

    if (a == 0 && b == 0)
    {
        num1.push_back(0);
        num2.push_back(0);
    }

    while (a > 0 || b > 0)
    {
        if (a > 0)
        {
            ll digit = a % 10;
            num1.push_back(digit);
            a = a / 10;
        }
        else
        {
            num1.push_back(0);
        }
        if (b > 0)
        {
            ll digit = b % 10;
            num2.push_back(digit);
            b = b / 10;
        }
        else
        {
            num2.push_back(0);
        }
    }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    ll n = num1.size();
    vector<vector<vector<vector<vector<ll>>>>> dp(20, vector<vector<vector<vector<ll>>>>(11, vector<vector<vector<ll>>>(2, vector<vector<ll>>(2, vector<ll>(2, -1)))));
    cout << solveRec(0, false, true, true, -1, n, num1, num2, dp) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    // cin>>t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}