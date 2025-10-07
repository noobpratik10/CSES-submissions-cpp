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
#define ll long long

bool isPos(ll mid, vector<int> &arr, int t, int n)
{
    ll made = 0;
    for (int i = 0; i < n; i++)
    {
        made += mid / arr[i];
        if (made >= 1ll * t)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxTimeMach = *max_element(arr.begin(), arr.end());
    ll low = 1;
    ll high = 1ll * t * maxTimeMach;
    ll ans = LLONG_MAX;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (isPos(mid, arr, t, n))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        // cout<<mid<<endl;
        // cout<<ans<<endl;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    // cin>>t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}