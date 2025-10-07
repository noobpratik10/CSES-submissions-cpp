/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    sort(wt.begin(), wt.end());

    int i = 0, j = n - 1;
    int cnt = 0;
    while (i <= j)
    {
        if (i != j)
        {
            if (wt[i] + wt[j] <= x)
            {
                i++;
                j--;
            }
            else
            {
                j--;
            }
            cnt++;
        }
        else
        {
            cnt++;
            i++;
            j--;
        }
    }
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}