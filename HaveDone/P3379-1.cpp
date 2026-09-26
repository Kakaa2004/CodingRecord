#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
struct Edge{
    int next;
    int to;
}edge[N<<1];
int head[N];
int cnt;
int n,m,s,cntd;
int fa[N],dep[N],dfn[N],top[N],son[N],siz[N];
void init(){
    cnt = 0;
    cntd = 0;
    for(int i = 0;i < N;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs1(int u,int f){
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] =  1;
    for(int i = head[u];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v!=f){
            dfs1(v,u);
            siz[u] += siz[v];
            if(son[u]==0||siz[v]>siz[son[u]]){
                son[u] = v;
            }
        }
    }
}
void dfs2(int u,int t){
    top[u] = t;
    dfn[u] = ++cntd;
    if(son[u] == 0){
        return;
    }
    dfs2(son[u],t);
    for(int i = head[u];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v!=fa[u]&&v!=son[u]){
            dfs2(v,v);
        }
    }
}
int lca(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]>=dep[top[b]]){
            a = fa[top[a]];
        }else{
            b = fa[top[b]];
        }
    }
    return (dfn[a]<=dfn[b]?a:b);
}
void solve(){
    init();
    cin >> n >> m >> s;
    for(int i = 0;i < n-1;i++){
        int u,v;cin >> u >> v;
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs1(s,0);
    dfs2(s,s);
    for(int i = 0;i < m;i++){
        int a,b;cin >> a >> b;
        cout<<lca(a,b)<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}