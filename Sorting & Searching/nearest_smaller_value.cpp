#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty() && arr[st.top()] < arr[i])
        {
            cout << st.top() + 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
        st.push(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
