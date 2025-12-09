// /******************************************************************************

//                               Online C++ Compiler.
//               Code, Compile, Run and Debug C++ program online.
// Write your code in this editor and press "Run" button to compile and execute it.

// *******************************************************************************/

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// void solve(){
//     int n, m;
//     cin>>n>>m;
//     vector<vector<int>>edges(m);
//     for(int i=0;i<m;i++){
//         int u,v,w;
//         cin>>u>>v>>w;
//         edges[i]={u-1,v-1,w};
//     }

//     //bellman ford --> 3 loops wala is NOT bellman ford
//     vector<ll>dist(n,LLONG_MAX);
//     dist[0]=0;
//     vector<int>par(n,-1);
//     for(int i=0;i<n-1;i++){
//         for(auto &e:edges){
//             if(dist[e[0]]!=LLONG_MAX && dist[e[1]]>dist[e[0]]+e[2]){
//                 dist[e[1]]=min(dist[e[1]],dist[e[0]]+e[2]);
//                 par[e[1]]=e[0];
//                 head=e[1];
//             }
//         }
//     }
//     int head=-1;
//     for(auto &e:edges){
//         if(dist[e[0]]!=LLONG_MAX && dist[e[1]]>dist[e[0]]+e[2]){
//             head=e[1];
//             break;
//         }
//     }

//     if(head==-1){
//         cout<<"NO"<<endl;
//         return;
//     }

//     for(int i=0;i<n;i++){
//         head=par[head];
//     }
//     vector<int>cycle;
//     int x=head;
//     do{
//         cycle.push_back(x);
//         x=par[x];
//     }while(x!=head && x!=-1);
//     cycle.push_back(x);
//     reverse(cycle.begin(),cycle.end());
//     cout<<"YES"<<endl;
//     for(auto &i:cycle){
//         cout<<i+1<<" ";
//     }cout<<endl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int t;
//     // cin>>t;
//     t=1;
//     while(t--){
//         solve();
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u - 1, v - 1, w};
    }

    vector<ll> dist(n, 0); // initialize to 0 to detect any negative cycle
    vector<int> par(n, -1);
    int head = -1;

    // Bellman-Ford
    for (int i = 0; i < n; i++)
    {
        head = -1;
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                head = v;
            }
        }
    }

    if (head == -1)
    {
        cout << "NO\n";
        return;
    }

    // move n steps to ensure inside the cycle
    for (int i = 0; i < n; i++)
        head = par[head];

    vector<int> cycle;
    int cur = head;
    do
    {
        cycle.push_back(cur);
        cur = par[cur];
    } while (cur != head);

    cycle.push_back(head); // close the cycle
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int x : cycle)
        cout << x + 1 << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
