#include <bits/stdc++.h>
using namespace std;
void solveRec(int n, int a, int b, int c)
{
    if (n == 0)
        return;

    solveRec(n - 1, a, c, b);
    cout << a << " " << c << endl;
    solveRec(n - 1, b, a, c);
}

int main()
{
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    int a = 1, b = 2, c = 3;
    solveRec(n, a, b, c);
    return 0;
}