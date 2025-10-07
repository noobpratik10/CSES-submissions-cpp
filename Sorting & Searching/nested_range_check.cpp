#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> range(n, vector<int>(2));
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> range[i][0] >> range[i][1];
        string s = to_string(range[i][0]) + "|" + to_string(range[i][1]);
        mp[s] = i;
    }

    sort(range.begin(), range.end(), [](auto &a, auto &b)
         {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0]; });

    vector<bool> inside(n);
    vector<bool> contain(n);
    int maxEnd = 0;
    for (int i = 0; i < n; i++)
    {
        if (range[i][1] <= maxEnd)
        {
            string s = to_string(range[i][0]) + "|" + to_string(range[i][1]);
            int ind = mp[s];
            inside[ind] = true;
        }
        maxEnd = max(maxEnd, range[i][1]);
    }
    int minEnd = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (range[i][1] >= minEnd)
        {
            string s = to_string(range[i][0]) + "|" + to_string(range[i][1]);
            int ind = mp[s];
            contain[ind] = true;
        }
        minEnd = min(minEnd, range[i][1]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << contain[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << inside[i] << " ";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}