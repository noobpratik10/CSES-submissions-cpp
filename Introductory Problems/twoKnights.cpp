#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int n;
    cin >> n;
    for (unsigned long long int k = 1; k <= n; k++)
    {
        cout << (k * k * k * k - 9 * k * k + 24 * k - 16) / 2 << endl;
    }
    return 0;
}