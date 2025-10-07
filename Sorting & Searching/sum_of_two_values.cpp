#include <bits/stdc++.h>
using namespace std;

int clower_bound(int n, int x, vector<vector<int>> &arr)
{
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid][0] == x)
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else if (x < arr[mid][0])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

void solve()
{
    int n, sum;
    cin >> n >> sum;
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        arr[i][1] = i; // store original index
    }

    sort(arr.begin(), arr.end(), [](auto &a, auto &b)
         { return a[0] < b[0]; });

    for (int i = 0; i < n; i++)
    {
        int x = sum - arr[i][0];
        int idx = clower_bound(n, x, arr);
        if (idx < n && arr[idx][0] == x && idx != i)
        {
            if (arr[i][1] > arr[idx][1])
                swap(arr[i][1], arr[idx][1]);
            cout << arr[i][1] + 1 << " " << arr[idx][1] + 1 << "\n";
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
