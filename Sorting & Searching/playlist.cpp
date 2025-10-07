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

    int i = 0, j = 0;
    int maxSeq = 0;
    map<int, int> cnt;
    while (j < n)
    {
        cnt[arr[j]]++;

        while (i < j && cnt.size() < (j - i + 1))
        {
            cnt[arr[i]]--;
            if (cnt[arr[i]] == 0)
            {
                cnt.erase(arr[i]);
            }
            i++;
        }

        if (cnt.size() == (j - i + 1))
        {
            maxSeq = max(maxSeq, j - i + 1);
        }
        j++;
    }

    cout << maxSeq << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
