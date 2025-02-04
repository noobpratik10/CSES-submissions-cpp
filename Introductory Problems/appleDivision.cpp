#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solveRec(ll index, ll curSum, vector<ll> &arr, ll &sum)
{
    if (index >= arr.size())
    {
        return abs(2 * curSum - sum);
    }
    ll ans = LLONG_MAX;
    ans = min(ans, solveRec(index + 1, curSum + arr[index], arr, sum));
    ans = min(ans, solveRec(index + 1, curSum + 0, arr, sum));
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    cout << solveRec(0, 0, arr, sum) << endl;
    return 0;
}