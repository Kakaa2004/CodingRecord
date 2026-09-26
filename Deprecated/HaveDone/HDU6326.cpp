#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll cost[N],reward[N];
int n;
int cnt;
int del[N];
struct Edge{
    int to;
    int next;
}edge[N<<1];
struct Node{
    int x;
    ll a,b;
    int tag;
    bool operator< (const Node &x) const {//流水线排序         因为是优先队列，和正常的排序是反的
       if(a>=b&&x.a< x.b) return true;
       if(a< b&&x.a>=x.b) return false;
       if(a< b&&x.a< x.b) return a>x.a;//对于a< b的，按照a从小到大
       if(a>=b&&x.a>=x.b) return b<x.b;//对于a>=b的，按照b从大到小    
    }
};
int head[N];
int fa[N];
void init(){
    cnt = 0;
    for(int i = 0;i < N;i++) head[i] = -1,del[i] = 0;
}
void addEdge(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int x,int f){
    fa[x] = f;
    for(int i = head[x];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v!=f){
            dfs(v,x);
        }
    }
}
int find(int x){
    if(del[fa[x]]){
        return fa[x] = find(fa[x]);
    }else return fa[x];
}
void solve(){
    priority_queue<Node>q;
    init();
    cin >> n;
    for(int i  = 2;i <= n;i++) cin >> cost[i] >> reward[i],q.push({i,cost[i],reward[i],0});
    for(int i = 2;i <= n;i++){
        int u,v;cin >> u >> v;
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1,0);
    vector<int>vis(n+1);
    int ct = 1;
    cost[1] = 0;
    reward[1] = 0;
    while(q.size()){
        Node p = q.top();q.pop();
        int u = p.x;
        if(del[u] || p.tag != vis[u]) continue;
        del[u] = 1;
        int f = find(u);
        ll A = min(cost[f],cost[u]+cost[f]-reward[f]);
        ll B = reward[u]+reward[f]-cost[u]-cost[f]+A;
        cost[f] = A;
        reward[f] = B;
        if(f>1){
            q.push({f,cost[f],reward[f],++ct});
            vis[f] = ct;
        }
    }
    cout<<cost[1]<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;cin >> t;
    while(t--) solve();
    return 0;
}