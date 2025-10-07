/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, n;
    cin >> x >> n;

    multiset<int> pq; // size
    set<int> st;      // parts
    st.insert(0);
    st.insert(x);
    pq.insert(x);

    for (int i = 0; i < n; i++)
    {
        int part;
        cin >> part;
        auto uitr = st.upper_bound(part);
        auto litr = uitr;
        litr--;
        int upper = *uitr, lower = *litr;

        auto prev = pq.find(upper - lower);
        pq.erase(prev);

        pq.insert(part - lower);
        pq.insert(upper - part);
        st.insert(part);

        cout << *pq.rbegin() << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}