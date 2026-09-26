#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
struct Edge{
	int to;
	int w;
	int next;
}edge[N<<1];
struct node{
	int u;
	int w;
	bool operator <(const node &a)const{
		return w>a.w;
	}
};
int head[N];
int cnt;
void init(){
	cnt = 0;
	for(int i = 0;i < N;i++){
		head[i] = -1;
	}
}
void addEdge(int u,int v,int w){
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
void solve(){
	init();
	int n,m;cin >> n >> m;
	vector<int>ans(10);
	ans[0] = 1;
	for(int i = 1;i <= 5;i++){
		cin >> ans[i];
	}
	for(int i = 0,u,v,w;i < m;i++){
		cin >> u >> v >> w;
		addEdge(u,v,w);
		addEdge(v,u,w);
	}
	vector<vector<int>>dis(10,vector<int>(N,inf));
	for(int i = 0;i < 6;i++){
		vector<bool>vis(n+1);
		priority_queue<node>q;
		q.push({ans[i],0});
		dis[i][ans[i]]= 0;
		while(!q.empty()){
			auto [u,d] = q.top();q.pop();
			if(vis[u]) continue;
			vis[u] = true;
			for(int j = head[u];~j;j = edge[j].next){
				int v = edge[j].to;
				int w = edge[j].w;
				if(vis[v]) continue;
				if(d + w < dis[i][v]){
					dis[i][v] = d+w;
					q.push({v,dis[i][v]});
				}
			}
		}
	}
	int res = inf;
	vector<int> p = {1,2,3,4,5};
    do{
        int rec = dis[0][ans[p[0]]];
        for(int i = 0;i < 4;i++){
            rec += dis[p[i]][ans[p[i+1]]];
        }
        res = min(res,rec);
    }while(next_permutation(p.begin(),p.end()));
    cout<<res;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t = 1;
	while(t--){
		solve();
	} 
	return 0;
}