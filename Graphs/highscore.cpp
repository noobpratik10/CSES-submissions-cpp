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
	vector<vector<int>>edges;
	for(int i=0; i<m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({u-1,v-1,w});
	    adj[u-1].push_back({v-1,w});
	}
        
	vector<long long>dist(n,LLONG_MIN);
		dist[0]=0;
		for(int v=0; v<n-1; v++) {
			for(int i=0; i<m; i++) {
				if(dist[edges[i][0]]!=LLONG_MIN && dist[edges[i][1]]<dist[edges[i][0]]+1ll*edges[i][2]) {
					dist[edges[i][1]]=max(dist[edges[i][1]],dist[edges[i][0]]+1ll*edges[i][2]);
				}
			}
		}
		vector<int>vis(n,false);
		queue<int>q;
		for(int i=0; i<m; i++) {
			if(dist[edges[i][0]]!=LLONG_MIN && dist[edges[i][1]]<dist[edges[i][0]]+1ll*edges[i][2]) {
			    dist[edges[i][1]]=dist[edges[i][0]]+1ll*edges[i][2];
			    q.push(edges[i][1]);
			    vis[edges[i][1]]=true;
			}
		}
		while(!q.empty()){
		    auto front=q.front();
		    q.pop();
		    
		    for(auto nbr:adj[front]){
		        if(!vis[nbr[0]]){
		            q.push(nbr[0]);
		            vis[nbr[0]]=true;
		        }
		    }
		}
		if(vis[n-1]){
		    cout<<-1<<endl;
		}else{
		    cout<<dist[n-1]<<endl;
		}
	return 0;
}