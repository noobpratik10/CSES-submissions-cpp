// #include <bits/stdc++.h>
// using namespace std;

// #define mod 1000000007
// #define ll long long

// class Compare
// {
// public:
//     bool operator()(const vector<int> &a, const vector<int> &b)
//     {
//         if (a[1] == b[1])
//         {
//             return a[0] < b[0];
//         }
//         return a[1] < b[1];
//     }
// };

// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<vector<int>> arr(n, vector<int>(2));
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i][0] >> arr[i][1];
//     }
//     priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // end time, user
//     for (int i = 0; i < k; i++)
//         pq.push({0, i});
//     Compare cmp;
//     sort(arr.begin(), arr.end(), cmp);
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (!pq.empty() && pq.top()[0] < arr[i][0])
//         {
//             auto top = pq.top();
//             pq.pop();
//             top[0] = arr[i][1];
//             cnt++;
//             pq.push(top);
//         }
//     }
//     cout << cnt << endl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     solve();

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Compare
{
public:
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1];

    Compare cmp;
    sort(arr.begin(), arr.end(), cmp); // sort by end time

    // store end times of currently busy users (min-heap)
    multiset<int> pq;
    for (int i = 0; i < k; i++)
        pq.insert(0); // all free at time 0

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = pq.upper_bound(arr[i][0]); // first end time > start time
        if (it == pq.begin())
            continue; // no one free before movie starts
        --it;         // last watcher who is free before start
        pq.erase(it);
        pq.insert(arr[i][1]); // this watcher now busy until movie end
        cnt++;
    }

    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
