#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge{
	int u,v,w;
};

struct DisjointSet{
	std::vector<int> par,size;
	DisjointSet(int n){
		par.resize(n),size.resize(n);
		for (int i = 0; i < n; ++i)
		{
			par[i]=i; size[i]=1;
		}
	}

	int find(int u){
		return (u==par[u]?u:par[u]=find(par[u]));
	}

	void connect(int u, int v){
		u=find(u),v=find(v);
		if(u==v) return;
		if(size[u]<size[v]) swap(u,v);
		par[v]=u;
		size[u]+=size[v];
	}
	bool connected(int u, int v){
		return (find(u)==find(v));
	}

};

vector<edge> E;
auto f=[](edge &e1,edge& e2){
	return e1.w<e2.w;
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		E.clear(),E.resize(n);
		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			u--,v--;
			E.push_back({u,v,w});
		}

		sort(E.begin(),E.end(),f);
		DisjointSet dcu(n);
		int mst=0;

		for(auto&e :E){
			if(!dcu.connected(e.u,e.v)){
				dcu.connect(e.u,e.v);
				mst+=e.w;
			}
		}
		cout<<"mst = "<<mst<<endl;
	}
	return 0;
}