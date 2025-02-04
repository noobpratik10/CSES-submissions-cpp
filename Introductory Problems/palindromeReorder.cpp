#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (auto c : s)
        cnt[c - 'A']++;
    int odCnt = 0;
    char odChar = '&';
    int odFreq = -1;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 != 0)
        {
            odCnt++;
            odChar = 'A' + i;
            odFreq = cnt[i];
        }
    }
    if (odCnt > 1)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        string even;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > 0 && cnt[i] % 2 == 0)
            {
                for (int j = 0; j < cnt[i] / 2; j++)
                {
                    even += 'A' + i;
                }
            }
        }
        string reven = even;
        reverse(reven.begin(), reven.end());
        string od;
        for (int i = 0; i < odFreq; i++)
            od += odChar;
        cout << even + od + reven << endl;
    }
    return 0;
}