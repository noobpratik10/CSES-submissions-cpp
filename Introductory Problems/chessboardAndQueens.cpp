#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board)
{
    bool ans = true;
    for (int i = row, j = col; i >= 0 && j >= 0 && i < 8 && j < 8; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            ans = false;
            break;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0 && i < 8 && j < 8; i--)
    {
        if (board[i][j] == 'Q')
        {
            ans = false;
            break;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0 && i < 8 && j < 8; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            ans = false;
            break;
        }
    }
    return ans;
}

int solveRec(int row, vector<string> &board)
{
    if (row >= 8)
    {
        return 1;
    }

    int ans = 0;
    for (int col = 0; col < 8; col++)
    {
        if (board[row][col] == '*')
            continue;
        else
        {
            if (isSafe(row, col, board))
            {
                board[row][col] = 'Q';
                ans += solveRec(row + 1, board);
                board[row][col] = '.';
            }
        }
    }
    return ans;
}

int main()
{
    vector<string> board(8);
    for (int i = 0; i < 8; i++)
        cin >> board[i];
    cout << solveRec(0, board) << endl;
    return 0;
}