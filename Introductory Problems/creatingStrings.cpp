#include <bits/stdc++.h>
using namespace std;

void solveRec(int index, int n, string curS, vector<int> &cnt,
              unordered_set<string> &st, vector<string> &ans)
{
    if (index >= n)
    {
        if (st.find(curS) == st.end())
        {
            ans.push_back(curS);
            st.insert(curS);
        }
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] > 0)
        {
            curS += 'a' + i;
            cnt[i]--;
            solveRec(index + 1, n, curS, cnt, st, ans);
            curS.pop_back();
            cnt[i]++;
        }
    }
}

int main()
{
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (auto c : s)
        cnt[c - 'a']++;
    vector<string> ans;
    unordered_set<string> st;
    solveRec(0, s.length(), "", cnt, st, ans);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto &i : ans)
        cout << i << endl;
    return 0;
}