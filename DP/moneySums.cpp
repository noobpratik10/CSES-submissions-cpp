#include <bits/stdc++.h>
using namespace std;

// bool solveRec(int index, int m, int &n, vector<int> &coins)
// {
//     if (index >= n)
//         return (m == 0);

//     bool ans = false;
//     if (m >= coins[index])
//         ans = ans || solveRec(index + 1, m - coins[index], n, coins);
//     ans = ans || solveRec(index + 1, m, n, coins);
//     return ans;
// }

// void solveRec(int index, int val, int &n, vector<int> &coins, unordered_set<int> &st)
// {
//     if (index >= n)
//     {
//         if (val > 0)
//             st.insert(val);
//         return;
//     }

//     solveRec(index + 1, val, n, coins, st);
//     solveRec(index + 1, val + coins[index], n, coins, st);
// }

void solveRec(int index, int sum, vector<int> &coins, set<int> &ans, unordered_map<string, bool> &dp)
{
    if (index >= coins.size())
    {
        if (sum > 0)
            ans.insert(sum);
        return;
    }
    string key = to_string(index) + "-" + to_string(sum);
    if (dp.find(key) != dp.end())
        return;

    solveRec(index + 1, sum + coins[index], coins, ans, dp);
    solveRec(index + 1, sum, coins, ans, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    // int mini = *min_element(coins.begin(), coins.end());
    // int maxi = accumulate(coins.begin(), coins.end(), 0);

    // vector<int> ans;
    // for (int m = mini; m <= maxi; m++)
    //     if (solveRec(0, m, n, coins))
    //         ans.push_back(m);

    // cout << ans.size() << endl;
    // for (auto i : ans)
    //     cout << i << " ";

    // unordered_set<int> st;
    // solveRec(0, 0, n, coins, st);
    // cout << st.size() << endl;
    // vector<int> ans;
    // for (auto i : st)
    //     ans.push_back(i);

    // sort(ans.begin(), ans.end());
    // for (auto i : ans)
    //     cout << i << " ";

    // set<int> ans;
    // unordered_map<string, bool> dp;
    // solveRec(0, 0, coins, ans, dp);

    // cout << ans.size() << endl;
    // for (auto i : ans)
    //     cout << i << " ";

    int maxSum = accumulate(coins.begin(), coins.end(), 0);
    vector<bool> dp(maxSum + 1, false);
    dp[0] = true;

    for (int coin : coins)
    {
        for (int j = maxSum; j >= coin; --j)
        {
            if (dp[j - coin])
            {
                dp[j] = true;
            }
        }
    }

    set<int> possibleSums;
    for (int i = 1; i <= maxSum; i++)
    {
        if (dp[i])
        {
            possibleSums.insert(i);
        }
    }

    // Print the result
    cout << possibleSums.size() << endl;
    for (int sum : possibleSums)
    {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}