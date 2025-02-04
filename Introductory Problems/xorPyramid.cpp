#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> prev(n);
    for (int i = 0; i < n; i++)
        cin >> prev[i];

    for (int i = 0; i < n; i++)
    {
        vector<int> curr(prev.size() - 1);
        for (int j = 0; j < prev.size() - 1; j++)
        {
            curr[j] = prev[j] ^ prev[j + 1];
        }
        prev.resize(prev.size() - 1);
        prev = curr;
    }
    cout << prev[0] << endl;
    return 0;
}