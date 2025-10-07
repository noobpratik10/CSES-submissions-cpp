/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    
    vector<vector<vector<int>>>adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u-1].push_back({v-1,w});
    }
    
    // dist[node][discount_used] where discount_used: 0=not used, 1=used
    vector<vector<long long>>dist(n,vector<long long>(2,LLONG_MAX));
    priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;
    
    dist[0][0] = 0;
    pq.push({0,0,0}); // {distance, discount_used, node}
    
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        
        long long d = top[0];
        int discount_used = top[1]; 
        int u = top[2];
        
        // CRITICAL: Skip if outdated to avoid TLE
        if(d > dist[u][discount_used]) continue;
        
        for(auto nbr : adj[u]){
            int v = nbr[0];
            int w = nbr[1];
            
            // Transition without using discount
            if(dist[v][discount_used] > dist[u][discount_used] + w){
                dist[v][discount_used] = dist[u][discount_used] + w;
                pq.push({dist[v][discount_used], discount_used, v});
            }
            
            // Transition using discount (only if not already used)
            if(discount_used == 0 && dist[v][1] > dist[u][0] + w/2){
                dist[v][1] = dist[u][0] + w/2;
                pq.push({dist[v][1], 1, v});
            }
        }
    }
    
    cout << min(dist[n-1][0], dist[n-1][1]) << endl;
    
    return 0;
}
