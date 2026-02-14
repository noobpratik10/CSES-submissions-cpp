#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        arr[i][1] = i;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int search = x - (arr[i][0] + arr[j][0]);
            int low = j + 1;
            int high = n - 1;
            int idx = n;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (arr[mid][0] > search)
                {
                    high = mid - 1;
                }
                else if (arr[mid][0] < search)
                {
                    low = mid + 1;
                }
                else
                {
                    idx = mid;
                    break;
                }
            }
            if (idx < n)
            {
                vector<int> ans = {arr[i][1] + 1, arr[j][1] + 1, arr[idx][1] + 1};
                sort(ans.begin(), ans.end());
                for (auto i : ans)
                {
                    cout << i << " ";
                }
                return;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
