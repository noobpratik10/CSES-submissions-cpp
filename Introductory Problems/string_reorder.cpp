#include <bits/stdc++.h>
using namespace std;

void solve()
{

    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'A']++;

    // Feasibility check
    int maxf = *max_element(freq.begin(), freq.end());
    if (maxf > (n + 1) / 2)
    {
        cout << -1 << "\n";
        return;
    }

    string result;
    result.reserve(n);

    // Build the string greedily
    for (int pos = 0; pos < n; pos++)
    {
        bool placed = false;
        for (int c = 0; c < 26; c++)
        {
            if (freq[c] == 0)
                continue;
            if (!result.empty() && result.back() == char('A' + c))
                continue;

            // Tentatively use this char
            freq[c]--;
            int remaining = n - pos - 1;

            // Check feasibility after choosing this char
            int maxf2 = *max_element(freq.begin(), freq.end());
            if (maxf2 <= (remaining + 1) / 2)
            {
                result.push_back('A' + c);
                placed = true;
                break;
            }
            // Backtrack
            freq[c]++;
        }
        if (!placed)
        {
            cout << -1 << "\n";
            return;
        }
    }

    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
