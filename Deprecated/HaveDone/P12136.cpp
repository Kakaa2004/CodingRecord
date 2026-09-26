#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1050;
struct Edge{
    int to;
    int next;
}edge[N<<1];
int head[N],w[N];
int n,cnt;
int dp[N][N];
void init(){
    cnt = 0;
    for(int i = 0;i < N;i++){
        head[i] = -1;
        dp[i][0] = 1;
    }
}
void addEdge(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int u,int f){
    int cnt = 0;
    for(int i = head[u];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v == f) continue;
        cnt++;
        dfs(v,u);
        for(int j = w[u]; j >= 1;j--){
            for(int k = 1; k <= min(j,w[v]);k++){
                dp[u][j] |= dp[u][j-k]&dp[v][k];
            }
        }
    }
    if(!cnt){
        dp[u][w[u]] = 1;
        return ;
    }
}
void solve(){
    init();
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> w[i];
    }
    for(int i = 0;i < n-1;i++){
        int u,v; cin >> u >> v;
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1,-1);
    int ans = 0;
    for(int i = 1;i <= 1000;i++){
        if(dp[1][i]) ans = i;
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}