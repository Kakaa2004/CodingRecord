#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e18;
const ll mod = 998244353;
const ll MOD = 1e9+7;
const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
struct Edge{
    int u,v,w;
    bool operator <(const Edge& e)const{
        return w < e.w;
    }
};
struct DSU{
    int n;
    vector<int>fa;
    DSU(int n):n(n){
        fa.resize(2*n+5);
        iota(fa.begin(),fa.end(),0);
    }
    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void merge(int x,int y){
        int fx = find(x),fy = find(y);
        if(fx == fy) return ;
        fa[fy] = fx;
        return;
    }
};
void solve(){
    const int LOG = 20;
    int n,m;cin >> n >> m;
    int tot = n;
    vector<Edge>a(m);
    for(int i = 0;i < m;i++){
        int u,v,w;cin >> u >> v >> w;
        a[i] = {u,v,w};
    }

    DSU dsu(n);
    sort(a.begin(),a.end());
    vector<vector<int>>g(2*n + 1);
    vector<int>val(2*n+1);
    for(auto& [u,v,w]:a){
        int fx = dsu.find(u),fy = dsu.find(v);
        if(fx == fy) continue;
        int fa = ++tot;
        val[fa] = w;
        dsu.merge(fa,fx);
        dsu.merge(fa,fy);
        g[fa].push_back(fx);
        g[fa].push_back(fy);
    }

    vector<array<int,LOG + 1>>jump(tot + 1);
    vector<int>dep(tot + 1);
    auto dfs = [&](auto&& self,int u,int fa)->void{
        jump[u][0] = fa;
        for(int i = 1;i <= LOG;i++){
            jump[u][i] = jump[jump[u][i-1]][i-1];
        }
        for(auto& v:g[u]){
            dep[v] = dep[u] + 1;
            self(self,v,u);
        }
    };
    for(int i = n+1;i <= tot;i++){
        if(dsu.find(i) != i) continue;
        dep[i] = 0;
        dfs(dfs,i,0);
    }
    auto lca = [&](int u,int v)->int{
        if(dep[u] < dep[v]) swap(u,v);
        int d = dep[u]-dep[v];
        for(int i = 0;i <= LOG;i++){
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
    int q;cin >> q;
    while(q--){
        int u,v;cin >> u >> v;
        if(dsu.find(u) != dsu.find(v)){
            cout<<"impossible\n";
        }else cout<<val[lca(u,v)]<<"\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}