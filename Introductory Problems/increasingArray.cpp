#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long diff = 0;
    long long prevMax = arr[0];
    for (long long i = 1; i < n; i++)
    {
        diff += max(0LL, prevMax - arr[i]);
        prevMax = max(prevMax, arr[i]);
    }
    cout << diff << endl;
    return 0;
}