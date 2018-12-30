#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

#define INF 123456789
using namespace std;

struct edge{
	int v,  w;
};

struct node{
	int d,  v;
};

auto f=[](node&p1, node&p2){
	return p1.d>p2.d;
};

typedef vector<vector<edge>> graph;
typedef priority_queue<node,vector<node>,decltype(f)> minheap;

graph g;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int vis[n+1],dist[n+1];
		for(int i=0;i<=n;i++){
			dist[i]=INF;
			vis[i]=0;
		}
		g.clear(),g.resize(n+1);
		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			g[u].push_back({v,w}),g[v].push_back({u,w});
		}

		int src,dest;
		cin>>src>>dest;

		minheap pq(f);

		pq.push({dist[src]=0,src});

		while(!pq.empty()){
			auto p=pq.top();
			pq.pop();
			if(vis[p.v]) continue;
			vis[p.v]=1;
			if(p.v==dest)	break;
			for(auto&e :g[p.v]){
				if(!vis[e.v]&&dist[e.v]>p.d+e.w){
					pq.push({dist[e.v]=p.d+e.w,e.v});
				}
			}
		}
		cout<<dist[dest]<<endl;
	}
	return 0;
}