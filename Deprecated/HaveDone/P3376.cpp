#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
struct Edge{
    int to;
    ll w;
    int next;
}edge[10005];
int head[205];
ll mf[205];
int pre[205];
int cnt;
int n,m,s,t;
void init(){
    cnt = 0;
    for(int i = 0;i < 205;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v,ll w){
    edge[cnt] = {v,w,head[u]};
    head[u] = cnt++;
}
bool bfs(){
    memset(mf,0,sizeof(mf));
    queue<int>q;
    q.push(s);
    mf[s] = inf;
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i = head[u];~i;i = edge[i].next){
            int v = edge[i].to;
            if(edge[i].w && !mf[v]){
                mf[v] = min(mf[u],edge[i].w);
                pre[v] = i;
                if(v==t) return true;
                q.push(v);
            }
        }
    }
    return false;
}
ll ek(){
    ll flow = 0;
    while(bfs()){
        int v = t;
        while(v!=s){
            int tmp = pre[v];
            edge[tmp].w -= mf[t];
            edge[tmp^1].w += mf[t];
            v = edge[tmp^1].to;
        }
        flow += mf[t];
    }
    return flow;
}
void solve(){
    init();
    cin >> n >> m >> s >> t;
    for(int i = 1;i <= m;i++){
        int u,v,w;cin >> u >> v >> w;
        addEdge(u,v,w);
        addEdge(v,u,0);
    }
    cout<<ek();
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int T = 1;
    while(T--) solve();
    return 0;
}