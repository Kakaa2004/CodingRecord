#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
struct Edge{
    int next;
    int to;
}edge[2*N];
int head[N];
ll Size[N],dp[N],sum[N];
int n,cnt;
void init(){
    cnt = 0;
    for(int i = 0;i < N;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs1(int u,int fa){
    Size[u] =  1;
    sum[u] = 1;
    for(int i = head[u];i != -1;i = edge[i].next){
        int v = edge[i].to;
        if(v != fa){
            dfs1(v,u);
            Size[u] += Size[v];
            sum[u] += sum[v] + Size[v];
        }
    }
}
void dfs2(int u,int fa){
    for(int i = head[u];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v!=fa){
            dp[v] = dp[u] - Size[v] + n - Size[v];
            dfs2(v,u);
        }
    }
}
void solve(){
    init();
    cin >> n;
    for(int i = 0; i < n-1;i++){
        int u,v;cin >> u >> v;
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs1(1,0);
    dp[1] = sum[1];
    dfs2(1,0);
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        ans = min(ans,dp[i]);
    }
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