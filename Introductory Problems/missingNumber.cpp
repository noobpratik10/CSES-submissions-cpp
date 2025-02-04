#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int xorr = 0;
    for (int i = 1; i < n; i++)
    {
        xorr = xorr ^ i;
        int y;
        cin >> y;
        xorr = xorr ^ y;
    }
    cout << (xorr ^ n) << endl;
    return 0;
}