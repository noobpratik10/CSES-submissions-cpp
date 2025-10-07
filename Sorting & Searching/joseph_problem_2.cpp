#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        st.insert(i);
    }

    int curr = 0;
    for (int i = 1; i <= n; i++)
    {
        int s = st.size();
        curr = (curr + k) % s;

        auto itr = st.begin();
        advance(itr, curr);
        cout << *itr << " ";
        st.erase(itr);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}