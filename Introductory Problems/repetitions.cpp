#include <bits/stdc++.h>
using namespace std;
int main()
{
    ;
    string s;
    cin >> s;
    int maxi = 0;
    char prev = '#';
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (prev == '#')
        {
            cnt++;
        }
        else
        {
            if (s[i] == prev)
            {
                cnt++;
            }
            else
            {
                cnt = 1;
            }
        }
        maxi = max(maxi, cnt);
        prev = s[i];
    }
    cout << maxi << endl;
    return 0;
}