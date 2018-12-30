#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int inf=1e9;

int main(){

vector<int>g[N]; //Adjacnecy List
bool vis[N];	//Visited Array
int dis[N];		//Distance form root

int t;
cin>>t;

while(t--){
	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++)
	{
		g[i].clear();
		vis[i]=false;
		dis[i]=inf;
	}

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int s;
	cin>>s;
	queue<int>q;
	q.push(s);
	vis[s]=true;
	while(!q.empty()){

		int v=q.front();
		cout<<v<<" ";
		q.pop();

		for(int it :g[v])
		{
			if(!vis[it]){
				vis[it]=true;
				queue.push(it);
				dis[it]=dis[s]+1;
			}
		}
	}
}

}


