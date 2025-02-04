#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 5; n / i >= 1; i *= 5)
    {
        cnt += n / i;
    }
    cout << cnt << endl;
    return 0;
}