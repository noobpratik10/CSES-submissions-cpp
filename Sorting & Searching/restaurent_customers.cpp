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

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dep(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] >> dep[i];
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int ans = 0, cur = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        while (j < i && dep[j] <= arr[i])
        {
            cur--;
            j++;
        }
        cur++;
        ans = max(ans, cur);
        i++;
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