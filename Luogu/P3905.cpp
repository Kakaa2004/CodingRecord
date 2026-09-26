#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
const int inf = 0x3f3f3f3f;
int g[N][N];
int val[N][N];
void solve(){
	memset(g,0x3f,sizeof(g));
	int n,m;cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int u,v,w;cin >> u >> v >> w;
		g[u][v] = w;
		g[v][u] = w;
	}
	int d;cin >> d;
	for(int i = 1;i <= d;i++){
		int u,v;cin >> u >> v;
		val[u][v] = 1;
		val[v][u] = 1;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(g[i][j]!=inf){
				g[i][j] *= val[i][j];
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	int a,b;cin >> a >> b;
	cout<<g[a][b];
	
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t = 1;
	while(t--) solve();
	return 0;
}
