#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int solveRec(int index, int prev, int &m, int &n, vector<int> &arr)
{
    if (index >= n)
        return 1;

    int ans = 0;
    if (prev == -1)
    {
        if (arr[index] == 0)
        {
            for (int pos = 1; pos <= m; pos++)
            {
                ans += solveRec(index + 1, pos, m, n, arr);
            }
        }
        else
        {
            ans += solveRec(index + 1, arr[index], m, n, arr);
        }
    }
    else
    {
        if (arr[index] == 0)
        {
            if (prev + 1 <= m)
                ans += solveRec(index + 1, prev + 1, m, n, arr);
            if (prev - 1 >= 1)
                ans += solveRec(index + 1, prev - 1, m, n, arr);
        }
        else
        {
            if (abs(prev - arr[index]) <= 1)
            {
                ans += solveRec(index + 1, arr[index], m, n, arr);
            }
        }
    }
    return ans;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << solveRec(0, -1, m, n, arr) << endl;
    return 0;
}