/*
换根dp
子树的结果需要使用父亲的数据
第一次dfs先求出一个节点的数据
再利用这个数据一次求出其他节点
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
struct Edge{
    int to;
    int next;
}edge[2*N];
int head[N],sum[N][10],dp[N][10];
int n,cnt;
void init(){
    cnt = 0;
    for(int i = 0;i < N;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v){
    edge[cnt].to  = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs1(int x,int fa){
    for(int i = head[x];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v!=fa){
            dfs1(v,x);
            for(int j = 1;j <= 9;j++){
                sum[x][j] += sum[v][j-1];
            }
        }
    }
}
void dfs2(int x,int fa){
    for(int i = head[x];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v!=fa){
            for(int j = 1;j <= 9;j++){
                if(j==1) dp[v][j] += 1 + sum[v][j];
                else dp[v][j] += dp[x][j-1] - sum[v][j-2] + sum[v][j];
            }
            dfs2(v,x);
        }
    }
}
void solve(){
    init();
    cin >> n;
    for(int i = 0;i < n-1;i++){
        int u,v;
        cin >> u >> v;
        addEdge(u,v);
        addEdge(v,u);
    }
    for(int i = 0;i <= n;i++){
        sum[i][0] = dp[i][0] =  1;
    }
    dfs1(1,0);
    for(int i = 0;i <= 9;i++){
        dp[1][i] = sum[1][i];
    }
    dfs2(1,0);
    for(int i = 1;i <= n;i++){
        cout<<dp[i][9]<<" ";
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    
    return 0;
}