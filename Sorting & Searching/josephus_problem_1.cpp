#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        if (q.size() == 1)
        {
            cout << q.front();
            break;
        }
        else
        {
            q.push(q.front());
            q.pop();
            cout << q.front() << " ";
            q.pop();
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}