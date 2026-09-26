#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e18;
const ll mod = 998244353;
const ll MOD = 1e9+7;
const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
void solve(){
    int n,m,s;cin >> n >> m >> s;
    vector<vector<int>>g(n+1);
    for(int i = 1;i < n;i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    const int LOG = 20;
    vector<array<int,LOG + 1>>jump(n+1);
    vector<int>dep(n+1);
    auto dfs = [&](auto&& self,int u,int fa)->void{
        jump[u][0] = fa;
        for(int i = 1;i <= LOG;i++){
            jump[u][i] = jump[jump[u][i-1]][i-1];
        }
        for(auto& v:g[u]){
            if(v == fa) continue;
            dep[v] = dep[u] + 1;
            self(self,v,u);
        }
    };
    dep[s] = 0;
    dfs(dfs,s,0);
    auto lca = [&](int u,int v)->int{
        if(dep[u] < dep[v]) swap(u,v);
        int d = dep[u]-dep[v];
        for(int i = LOG;i>=0;i--){
            if((d>>i)&1) u = jump[u][i];
        }
        if(u == v) return u;
        for(int i = LOG;i>=0;i--){
            if(jump[u][i] != jump[v][i]){
                u = jump[u][i];
                v = jump[v][i];
            }
        }
        return jump[u][0];
    };
    while(m--){
        int u,v;cin >> u >> v;
        cout<<lca(u,v)<<"\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}