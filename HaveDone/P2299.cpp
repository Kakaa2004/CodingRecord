#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
struct Edge{
    int to;
    int w;
    int next;
}edge[400005];
struct Node{
    int x;
    int d;
    bool operator <(const Node& a)const{
        return d > a.d;
    }
};
int head[3000];
int cnt;
int n,m;
void init(){
    cnt = 0;
    for(int i = 0;i < 3000;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v,int w){
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void solve(){
    init();
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u,v,w;cin >> u >> v >> w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    vector<bool>done(n+1);
    vector<int>dis(n+1,inf);
    priority_queue<Node>q;
    q.push({1,0});
    dis[1] = 0;
    while(!q.empty()){
        auto [u,d] = q.top();q.pop();
        if(done[u]) continue;
        done[u] = true;
        for(int i = head[u];~i;i = edge[i].next){
            int v = edge[i].to;
            int w = edge[i].w;
            if(done[v]) continue;
            if(d + w < dis[v]){
                dis[v] = d+w;
                q.push({v,dis[v]});
            }
        }
    }
    cout<<dis[n];
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}