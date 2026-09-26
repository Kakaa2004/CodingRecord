#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef Complex<double> Complex;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const ll mod = 998244353;
const ll MOD = 1e9+7;
const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const int ddx[] = {1,1,-1,-1,2,2,-2,-2};
const int ddy[] = {2,-2,2,-2,1,-1,1,-1};
const int N = 4e5+5;
struct Edge{
    int to,next,w;
}edge[N<<1];
int head[N];
int cur[50000],d[50000],cnt,s,t;
bool mp[50000];
void addEdge(int u,int v,int w){
    edge[cnt] = {v,head[u],w};
    head[u] = cnt++;
}
bool bfs(){
    memset(d,0,sizeof(d));
    queue<int>q;
    q.push(s);d[s] = 0;
    while(q.size()){
        int u = q.front();q.pop();
        for(int i = head[u];~i;i = edge[i].next){
            int v = edge[i].to,w = edge[i].w;
            if(!d[v] && w > 0){
                d[v] = d[u] + 1;
                q.push(v);
                if(v == t) return true;
            }
        }
    }
    return false;
}
int dfs(int u,int flow){
    if(u == t) return flow;
    int sum = 0;
    for(int& i = cur[u];~i; i = edge[i].next){
        int v = edge[i].to;
        if(d[v] == d[u] + 1 && edge[i].w > 0){
            if(int f = dfs(v,min(flow,edge[i].w))){
                edge[i].w -= f;
                edge[i^1].w += f;
                sum += f;
                flow -= f;
                if(!flow) break;
            }
        }
    }
    if(!sum) d[u] = 0;
    return sum;
}
int Dinic(){
    int maxFlow = 0, phase = 0;
    while(bfs()){
        phase++;
        int before = maxFlow;
        memcpy(cur,head,sizeof(cur));
        int dfsCnt = 0;
        while(int f = dfs(s,inf)){
            maxFlow += f;
            dfsCnt++;
            if(dfsCnt > 10000000){ cerr << "phase "<<phase<<" too many dfs calls, stuck!\n"; return -1; }
        }
        cerr << "phase " << phase << " added " << (maxFlow-before) << " flow, total " << maxFlow << "\n";
        if(phase > 500){ cerr << "too many phases, stuck!\n"; return -1; }
    }
    return maxFlow;
}
void solve(){
    memset(head,-1,sizeof(head));
    int n,m;cin >> n >> m;
    int base = 205;
    auto encode = [&](int x,int y)->int{
        return x*base + y;
    };
    for(int i = 1;i <= m;i++){
        int x,y;cin >> x >> y;
        mp[encode(x,y)] = true;
    }
    int ans = n*n;
    s = 0,t = base*base;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int st = encode(i,j);
            if(mp[st]){
                ans--;
                continue;
            }
            if((i+j)&1){
                addEdge(st,t,1);
                addEdge(t,st,0);
                continue;
            }
            addEdge(s,st,1);
            addEdge(st,s,0);
            for(int k = 0;k < 8;k++){
                int x = i + ddx[k];
                int y = j + ddy[k];
                if(x < 1 || x > n || y < 1 || y > n) continue;
                int ed = encode(x,y);
                if(mp[ed]) continue;
                addEdge(st,ed,1);
                addEdge(ed,st,0);
            }
        }
    }
    ans -= Dinic();
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;//cin >> t;
    while(t--) solve();
    return 0;
} 