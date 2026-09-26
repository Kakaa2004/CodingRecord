#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+5;
struct Edge{
    int to;
    int next;
    int w;
}edge[N<<1];
int n;
int cnt;
int head[N];
int dp[N][2],f[N][2],vis[N][2];
void init(){
    cnt = 0;
    for(int i = 0;i < N;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v,int w){
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs1(int x,int fa){
    f[x][0] = 0,f[x][1] = 0;
    for(int i = head[x];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v!=fa){
            dfs1(v,x);
            if(f[v][0] + edge[i].w > f[x][0]){
                f[x][1] = f[x][0]; vis[x][1] = vis[x][0];
                f[x][0] = f[v][0] + edge[i].w; vis[x][0] = v;
            }else if(f[v][0] + edge[i].w > f[x][1]){
                f[x][1] = f[v][0] + edge[i].w;
                vis[x][1] = v;
            }
        }
    }
}
void dfs2(int x,int fa){
    for(int i = head[x];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v!=fa){
            if(vis[x][0] != v){
                if(f[x][0]+edge[i].w >= f[v][0]){
                    f[v][1] = f[v][0];vis[v][1] = vis[v][0];
                    f[v][0] = f[x][0] + edge[i].w;vis[v][0] = x;
                }else if(f[x][0]+edge[i].w >= f[v][1]){
                    f[v][1] = f[x][0]+edge[i].w;vis[v][1] = x;
                }
            }else{
                if(f[x][1]+edge[i].w >= f[v][0]){
                    f[v][1] = f[v][0];vis[v][1] = vis[v][0];
                    f[v][0] = f[x][1] + edge[i].w;vis[v][0] = x;
                }else if(f[x][1]+edge[i].w >= f[v][1]){
                    f[v][1] = f[x][1]+edge[i].w;vis[v][1] = x;
                }
            }
            dfs2(v,x);
        }
    }
}
void solve(){
    init();
    for(int i = 2;i <= n;i++){
        int v,w;cin >> v >> w;
        addEdge(i,v,w);
        addEdge(v,i,w);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    for(int i = 1;i <= n;i++){
        cout<<f[i][0]<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    while(cin >> n) solve();
    return 0;
}