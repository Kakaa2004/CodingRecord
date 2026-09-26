#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
struct Edge{
    int next;
    int to;
}edge[2*N],qEdge[2*N];
ll head[N],D[N],fa[N],qHead[N],vis[N],Fa[N],sum[N];
ll n,k,cnt,qCnt,ans;
void init(){
    cnt = 0;
    qCnt = 0;
    ans = 0;
    for(int i = 0;i < N;i++){
        head[i] = -1;
        qHead[i] = -1;
        Fa[i] = i;
        vis[i] = 0;
    }
}
int get(int x){
    return x == Fa[x] ? x : Fa[x] = get(Fa[x]);
}
void addEdge(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void addQEdge(int u,int v){
    qEdge[qCnt].to = v;
    qEdge[qCnt].next = qHead[u];
    qHead[u] = qCnt++;
}
void dfs1(int u,int father){
    
    fa[u] = father;
    for(int i = head[u]; i!= -1;i = edge[i].next){
        int v = edge[i].to;
        if(v!=father){
            dfs1(v,u);
            Fa[v] = u;
        }
    }
    for(int i = qHead[u];i!=-1;i = qEdge[i].next){
        int v = qEdge[i].to;
        if(vis[v]){
            //cout<<u<<"----"<<v<<"\n";
            D[u]++;
            D[v]++;
            int tmp = get(v);
            D[tmp]--;
            D[fa[tmp]]--;
        }
    }
    vis[u] = 1;
}
void dfs(int u,int father){
    for(int i = head[u];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v!=father){
            dfs(v,u);
            D[u] += D[v];
        }
    }
    ans = min(ans,D[u]);
}
void solve(){
    init();
    cin >> n >> k;
    for(int i = 0;i < n -1;i++){
        int u,v; cin >> u >> v;
        addEdge(u,v);
        addEdge(v,u);
    }
    for(int i = 0;i < k;i++){
        int u,v;cin >> u >> v;
        addQEdge(u,v);
        addQEdge(v,u);
    }
    dfs1(1,0);
    dfs(1,0);
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    
    return 0;
}