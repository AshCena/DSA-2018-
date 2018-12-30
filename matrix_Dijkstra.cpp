#include <bits/stdc++.h>
#define INF 123456789
using namespace std;

struct node{
	int d,x,y;
};

auto f=[](node& e1,node& e2){
	return e1.d>e2.d;
};
typedef priority_queue<node, vector<node> ,decltype(f)>  minheap;

int main() {
	vector<vector<int>> board(8,vector<int>(8,0));
	vector<vector<bool>> vis(8,vector<bool>(8,false));
	vector<vector<int>> dis(8,vector<int>(8,INF));
	
	int xMoves[]={1,-1,2,2,-2,-2,1,-1};
	int yMoves[]={2,2,1,-1,1,-1,-2,-2};
	
	minheap pq(f);
	int x1,y1,z,a;
	cin>>x1>>y1>>z>>a;
	pq.push({0,x1,y1});
	dis[x1][y1]=0;
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();
		int x=p.x;
		int y=p.y;
		vis[x][y]=true;
		if(x==z&&y==a){
			cout<<p.d;
			return 0;
		}
		for(int i=0;i<8;i++){

			if((x+xMoves[i])>=0 && (y+yMoves[i])>=0 && (x+xMoves[i])<8 && (y+yMoves[i])<8){
				if(!vis[x+xMoves[i]][y+yMoves[i]] && dis[x+xMoves[i]][y+yMoves[i]]>p.d+((x*(x+xMoves[i]))+(y*(y+yMoves[i])))){
						pq.push({dis[x+xMoves[i]][y+yMoves[i]]=p.d+((x*(x+xMoves[i]))+(y*(y+yMoves[i]))),x+xMoves[i],y+yMoves[i]});
				}
			}
		}
		
	}
	
	// if(dis[z][a]==INF){
	// 		cout<<-1;
	// 	}else
	// 	cout<<dis[z][a];
	
	return -1;
}