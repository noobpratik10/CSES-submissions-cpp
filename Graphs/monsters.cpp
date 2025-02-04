#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfsMonsters(vector<string> &mat, vector<vector<int>> &monsterTime, queue<pair<int, int>> &mq, int n, int m)
{
    while (!mq.empty())
    {
        int x = mq.front().first;
        int y = mq.front().second;
        mq.pop();

        for (auto dir : directions)
        {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (isValid(nx, ny, n, m) && mat[nx][ny] == '.' && monsterTime[nx][ny] == INT_MAX)
            {
                monsterTime[nx][ny] = monsterTime[x][y] + 1;
                mq.push({nx, ny});
            }
        }
    }
}

bool bfsPlayer(vector<string> &mat, vector<vector<int>> &monsterTime, vector<vector<pair<int, int>>> &parent,
               vector<int> &start, int n, int m, string &ans)
{
    queue<pair<int, int>> pq;
    vector<vector<int>> playerTime(n, vector<int>(m, INT_MAX));
    pq.push({start[0], start[1]});
    playerTime[start[0]][start[1]] = 0;

    while (!pq.empty())
    {
        int x = pq.front().first;
        int y = pq.front().second;
        pq.pop();

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
        {
            // Found an exit
            while (!(x == start[0] && y == start[1]))
            {
                int px = parent[x][y].first;
                int py = parent[x][y].second;
                if (px < x)
                    ans += 'D';
                else if (px > x)
                    ans += 'U';
                else if (py < y)
                    ans += 'R';
                else
                    ans += 'L';
                x = px;
                y = py;
            }
            reverse(ans.begin(), ans.end());
            return true;
        }

        for (auto dir : directions)
        {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (isValid(nx, ny, n, m) && mat[nx][ny] == '.' && playerTime[nx][ny] == INT_MAX &&
                playerTime[x][y] + 1 < monsterTime[nx][ny])
            {
                playerTime[nx][ny] = playerTime[x][y] + 1;
                parent[nx][ny] = {x, y};
                pq.push({nx, ny});
            }
        }
    }
    // cout << "Monster Time:" << endl;
    // for (auto i : monsterTime)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "Player Time:" << endl;
    // for (auto i : playerTime)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);

    vector<int> start;
    queue<pair<int, int>> mq;
    vector<vector<int>> monsterTime(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'A')
                start = {i, j};
            else if (mat[i][j] == 'M')
            {
                mq.push({i, j});
                monsterTime[i][j] = 0;
            }
        }
    }

    while (!mq.empty())
    {
        auto cell = mq.front();
        int x = cell.first, y = cell.second;
        mq.pop();

        for (auto dir : directions)
        {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (isValid(nx, ny, n, m) && mat[nx][ny] == '.' && monsterTime[nx][ny] > monsterTime[x][y] + 1)
            {
                monsterTime[nx][ny] = monsterTime[x][y] + 1;
                mq.push({nx, ny});
            }
        }
    }

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    string ans;
    if (bfsPlayer(mat, monsterTime, parent, start, n, m, ans))
    {
        cout << "YES" << endl;
        cout << ans.length() << endl;
        cout << ans << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
