/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

// sort ascending
//  ----
//    ------
//        -------
//                    -------
//                    ----
//                       ---------

// ----------
// ----
//      ----------

// SJF
#define ll long long
ll curTime = 0;

class Compare
{
public:
    bool operator()(const vector<ll> &a, const vector<ll> &b)
    {
        return a[0] > b[0];
    }
};

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(2));
    priority_queue<vector<ll>, vector<vector<ll>>, Compare> pq;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        pq.push({arr[i][0], arr[i][1]});
    }

    ll ans = 0;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        ans += (top[1] - (curTime + top[0]));
        curTime += top[0];
    }
    cout << ans << endl;
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