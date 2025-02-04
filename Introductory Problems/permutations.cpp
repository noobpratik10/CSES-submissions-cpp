#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    int j = n;
    vector<int> ans(n);
    bool flg = true;
    for (int a = 0; a < n; a++)
    {
        if (flg)
        {
            ans[a] = i;
            i++;
            flg = !flg;
        }
        else
        {
            ans[a] = j;
            j--;
            flg = !flg;
        }
    }
    rotate(ans.begin(), ans.begin() - 1, ans.end());
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}