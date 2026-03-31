/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<ll> prefSum(n, 0ll);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prefSum[i] = arr[i];
        if (i >= 1)
        {
            prefSum[i] += prefSum[i - 1];
        }
    }

    vector<ll> ans;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ll curAns = prefSum[b];
        if (a - 1 >= 0)
        {
            curAns -= prefSum[a - 1];
        }
        ans.push_back(curAns);
    }

    for (auto &i : ans)
    {
        cout << i << endl;
    }

    return 0;
}
