#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
struct Edge{
    int next;
    int to;
}edge[2*N];
ll MOD,n,m,root,cnt,cntg;
ll a[N],head[N];
ll tree[4*N],lazyTag[4*N];
ll fa[N],dep[N],son[N], siz[N],top[N],dfn[N],seg[N];
ll ls(int p){return (p<<1);}
ll rs(int p){return (p<<1)|1;}
void up(int p){
    tree[p] = (tree[ls(p)]+tree[rs(p)])%MOD;
}
void addTag(int l,int r,int p,ll k){
    tree[p] = ((r-l+1)*k%MOD + tree[p])%MOD;
    lazyTag[p] = (lazyTag[p]+k)%MOD;
}
void down(int l,int r,int p){
    if(lazyTag[p] != 0){
        int mid = (l+r)>>1;
        addTag(l,mid,ls(p),lazyTag[p]);
        addTag(mid+1,r,rs(p),lazyTag[p]);
        lazyTag[p] = 0;
    }
}
void update(int L,int R,ll k,int l,int r,int p){
    if(L<=l&&r<=R){
        addTag(l,r,p,k);
        return ;
    }
    down(l,r,p);
    int mid = (l+r)>>1;
    if(L <= mid) update(L,R,k,l,mid,ls(p));
    if(R > mid) update(L,R,k,mid+1,r,rs(p));
    up(p);
}
ll query(int L,int R,int l,int r,int p){
    if(L<=l&&r<=R){
        return tree[p]%MOD;
    }
    down(l,r,p);
    ll ans = 0;
    int mid = (l+r)>>1;
    if(L <= mid) ans = (ans + query(L,R,l,mid,ls(p)))%MOD;
    if(R > mid) ans = (ans + query(L,R,mid+1,r,rs(p)))%MOD;
    return ans%MOD;
}
void build(int l,int r,int p){
    if(l==r){
        tree[p] = a[seg[l]]%MOD;
        return ; 
    }
    int mid = (l+r)>>1;
    build(l,mid,ls(p));
    build(mid+1,r,rs(p));
    up(p);
}
void dfs1(int u,int f){
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] =  1;
    for(int i = head[u];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v != f){
            dfs1(v,u);
            siz[u] =(siz[u] + siz[v]);
            if(son[u] == 0 || siz[v] > siz[son[u]]){
                son[u] = v;
            }
        }
    }
}
void dfs2(int u,int t){
    dfn[u] = ++cntg;
    top[u] = t;
    seg[cntg] = u;
    if(son[u] == 0){
        return;
    }
    dfs2(son[u],t);
    for(int i = head[u];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v != fa[u] && v != son[u]){
            dfs2(v,v);
        }
    }
}
void init(){
    cnt = 0;
    cntg = 0;
    for(int i = 0;i < N;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next =  head[u];
    head[u] = cnt++;
}
void addPath(int x,int y,ll z){
    while(top[x]!=top[y]){
        if(dep[top[x]]>dep[top[y]]){
            update(dfn[top[x]],dfn[x],z,1,n,1);
            x = fa[top[x]];
        }else{
            update(dfn[top[y]],dfn[y],z,1,n,1);
            y = fa[top[y]];
        }
    }
    update(min(dfn[x],dfn[y]),min(dfn[x],dfn[y]),z,1,n,1);
}
void addSubTree(int x,ll z){
    update(dfn[x],dfn[x]+siz[x]-1,z,1,n,1);
}
int queryPath(int x,int y){
    ll ans = 0;
    while(top[x]!=top[y]){
        if(dep[top[x]]>dep[top[y]]){
            ans = (ans + query(dfn[top[x]],dfn[x],1,n,1))%MOD;
            x = fa[top[x]];
        }else{
            ans = (ans + query(dfn[top[y]],dfn[y],1,n,1))%MOD;
            y  = fa[top[y]];
        }
    }
    ans = (ans + query(min(dfn[x],dfn[y]),min(dfn[x],dfn[y]),1,n,1))%MOD;
    return ans%MOD;
}
int querySubTree(int x){ 
    return query(dfn[x],dfn[x] + siz[x] - 1,1,n,1)%MOD;
}
void solve(){
    init();
    cin >> n >> m >> root >> MOD;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    for(int i = 0;i < n-1;i++){
        int u,v;cin >> u >> v;
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs1(root,0);
    dfs2(root,root);
    build(1,n,1);
    for(int i = 0;i < m;i++){
        int op;cin >> op;
        if(op == 1){
            ll x,y,z;cin >> x >> y >> z;
            addPath(x,y,z);
        }else if(op == 2){
            ll x,y;cin >> x >> y;
            cout<<queryPath(x,y)%MOD<<"\n";
        }else if(op == 3){
            ll x,y;cin >> x >> y;
            addSubTree(x,y);
        }else{
            ll x;cin >> x;
            cout<<querySubTree(x)%MOD<<"\n";
        }
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