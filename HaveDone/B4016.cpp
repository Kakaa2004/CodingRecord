#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
vector<int> g[N];
int n,k,dep = -1;
void dfs(int u,int fa,int dis){
    if(dis > dep){
        k = u;
        dep = dis;
    }
    for(int i = 0;i < g[u].size();i++){
        int v = g[u][i];
        if(v != fa){
            dfs(v,u,dis+1);
        }
    }
}
void solve(){
    cin >> n;
    for(int i = 0;i < n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
    dfs(k,0,0);
    cout<<dep;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}