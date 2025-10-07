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
    vector<vector<int>> cust(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> cust[i][0] >> cust[i][1];
        cust[i][2] = i;
    }

    int maxRoom = 0;
    sort(cust.begin(), cust.end());
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (!pq.empty() && pq.top()[0] < cust[i][0])
        {
            ans[cust[i][2]] = pq.top()[1];
            auto top = pq.top();
            pq.pop();
            top[0] = cust[i][1];
            pq.push(top);
        }
        else
        {
            maxRoom++;
            ans[cust[i][2]] = maxRoom;
            pq.push({cust[i][1], maxRoom});
        }
    }

    cout << maxRoom << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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