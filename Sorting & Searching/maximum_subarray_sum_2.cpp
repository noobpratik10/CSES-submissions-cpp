/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// ll maxSum(int n,int b,vector<int>&arr){
//     ll sum=0;

// }

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> prefSum(n + 1);
    for (int i = 0; i < n; i++)
    {
        prefSum[i + 1] += prefSum[i] + arr[i];
    }

    ll ans = LLONG_MIN;
    multiset<ll> window;

    for (int i = a; i <= n; i++)
    {
        window.insert(prefSum[i - a]);

        if (i - b - 1 >= 0)
        {
            window.erase(window.find(prefSum[i - b - 1]));
        }
        ans = max(ans, prefSum[i] - *window.begin());
    }

    cout << ans << endl;
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