#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long maxSum = 0, curSum = 0;
    bool fnd = false;
    for (auto &i : arr)
    {
        if (curSum + i > 0)
        {
            curSum += i;
            fnd = true;
        }
        else
        {
            curSum = 0;
        }
        maxSum = max(maxSum, curSum);
    }
    if (!fnd)
    {
        cout << *max_element(arr.begin(), arr.end()) << endl;
        return;
    }
    cout << maxSum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
