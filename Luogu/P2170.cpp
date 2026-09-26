#include <iostream>
#include <algorithm>
#include <vector> 
#include <string>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int fa[N];
int sz[N]; 
int Find(int x){
	return fa[x] == x?x:fa[x] = Find(fa[x]);
}
void solve(){
	int n,m,k;cin >> n >> m >> k;
	for(int i = 1;i <= n;i++){
		fa[i] = i;
		sz[i] = 1;
	}
	for(int i = 1;i <= k;i++){
		int a,b;cin >> a >> b;
		int x = Find(a);
		int y = Find(b);
		if(x!=y){
			fa[x] = y;
			sz[y] += sz[x];
		}
	}
	vector<int>v;
	for(int i = 1;i <= n;i++){
		if(fa[i] == i){
			v.push_back(sz[i]);
		}
	}
	if(!m){
		cout<<0;
		return;
	}
	vector<int>dp(2*m+1);
	dp[0] = 1;
	int gap = 0;
	for(int i = 0;i < v.size();i++){
		for(int j = 2*m;j>=v[i];j--){
			if(dp[j]) continue;
			dp[j] = dp[j-v[i]];
			if(dp[j]){
				if(abs(j-m) < abs(gap-m)){
					gap = j;
				}else if(abs(j-m)==abs(gap-m)){
					gap = min(gap,j);
				}
			}
		}
	}
	cout<<gap;
	
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int t = 1;
	while(t--) solve();
	return 0;
}
