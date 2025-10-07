#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long q;
    cin >> q;
    while (q--)
    {
        long long k;
        cin >> k;

        long long i = 1;
        long long p10 = 1; // stores 10^(i-1)

        while (i * 9 * p10 <= k)
        {
            k -= i * 9 * p10;
            i++;
            p10 *= 10;
        }
        i--;

        long long digiN = i + 1;
        long long nextAdd = k / digiN;
        long long finN = (p10 - 1) + nextAdd;

        if (k % digiN == 0)
        {
            cout << finN % 10 << endl;
        }
        else
        {
            finN++;
            long long pos = k % digiN;
            string s = to_string(finN);
            cout << s[pos - 1] << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
