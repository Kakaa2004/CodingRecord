#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5+5;
const ll inf = 1e17;
struct Edge{
    int next;
    int to;
    ll w;
}edge[2*N];
int head[N];
bool done[N];
int cnt,n,m;
ll dist[N],minEdge[N];
struct node{
    int u;
    ll w;
    bool operator <(const node &a) const{
        return a.w < w;
    }
};
void init(){
    cnt = 0;
    for(int i = 0;i < N;i++){
        head[i] = -1;
        minEdge[i] = inf;
        dist[i] = inf;
    }
}
void addEdge(int u,int v,ll w){
    edge[cnt].to = v;
    edge[cnt].w  = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void solve(){
    init();
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        ll u,v,w; cin >> u >> v >> w;
        addEdge(u,v,w);
        if(u!=v) addEdge(v,u,w);
        minEdge[u] = min(minEdge[u],w);
        minEdge[v] = min(minEdge[v],w);
    }
    dist[1] = 0;
    priority_queue<node>q;
    q.push({1,dist[1]});
    while(q.size()){
        auto [u,w] = q.top();q.pop();
        if(done[u]) continue;
        done[u] = true;
        for(int i = head[u];i != -1;i = edge[i].next){
            int v = edge[i].to;
            if(v==u || done[v]) continue;
            ll tmp = min(edge[i].w,2*minEdge[u]);
            if(dist[v] >  w + tmp){
                dist[v] = w + tmp;
                q.push({v,dist[v]});
            }
            
        }
    }
    cout<<(done[n]?dist[n]:-1)<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    
    return 0;
}