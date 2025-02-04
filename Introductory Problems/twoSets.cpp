#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main()
{
    ll n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    if (sum % 2 == 0)
    {
        cout << "YES" << endl;
        vector<bool> flg(n + 1, false);
        ll cnt = 0;
        sum = sum / 2;
        ll cur = n;
        while (sum)
        {
            if (sum >= cur)
            {
                sum -= cur;
                flg[cur] = true;
                cnt++;
            }
            cur--;
        }

        cout << cnt << endl;
        for (ll i = 1; i <= n; i++)
            if (flg[i])
                cout << i << " ";
        cout << endl;
        cout << n - cnt << endl;
        for (ll i = 1; i <= n; i++)
            if (!flg[i])
                cout << i << " ";
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}