#include <bits/stdc++.h>
using namespace std;

void solveRec(int n, string s,
              unordered_set<string> &st)
{
    cout << s << endl;
    st.insert(s);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
            if (st.find(s) == st.end())
            {
                solveRec(n, s, st);
            }
            s[i] = '0';
        }
        else
        {
            s[i] = '0';
            if (st.find(s) == st.end())
            {
                solveRec(n, s, st);
            }
            s[i] = '1';
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string s(n, '0');
    unordered_set<string> st;
    solveRec(n, s, st);
    return 0;
}