#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<vector<int>> cord(t, vector<int>(2));
    for (int i = 0; i < t; i++)
    {
        unsigned long long int x, y;
        cin >> x >> y;

        unsigned long long int m = max(x, y);
        unsigned long long int num = m * m - (m - 1);
        unsigned long long int diff = m - min(x, y);

        if (m % 2 == 0)
        {
            if (x < m)
                cout << num - diff << endl;
            else if (y < m)
                cout << num + diff << endl;
            else
                cout << num << endl;
        }
        else
        {
            if (x < m)
                cout << num + diff << endl;
            else if (y < m)
                cout << num - diff << endl;
            else
                cout << num << endl;
        }
    }
    return 0;
}