#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
const int M = 5e5+5;
struct node{
    int next;
    int to;
}edge[2*N];
struct point{
    int next;
    int to;
    int num;
}q_edge[2*M];
int n,m,s,cnt,q_cnt;
int head[N],q_head[M],fa[N],ans[M];
bool vis[N];
void init(){
    cnt = q_cnt = 0;
    for(int i = 0;i < N;i++){
        head[i] = -1;
        vis[i] = false;
        fa[i] = i;
    }     
    for(int i = 0;i < M;i++){
        q_head[i] = -1;
    }
}
void addEdge(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
int find(int x){
    if(fa[x]==x){
        return x;
    }else{
        fa[x] = find(fa[x]);
        return fa[x];
    }
}
void tarjan(int x){
    vis[x] = true;
    for(int i = head[x];i!=-1;i = edge[i].next){
        int y = edge[i].to;
        if(!vis[y]){
            tarjan(y);
            fa[y] = x;
        }
    }
    for(int i = q_head[x];i!=-1;i = q_edge[i].next){
        int y = q_edge[i].to;
        if(vis[y]){
            ans[q_edge[i].num] = find(y);
        }
    }
    
}
void addEdge_q(int u,int v,int num){
    q_edge[q_cnt].to = v;
    q_edge[q_cnt].num = num;
    q_edge[q_cnt].next = q_head[u];
    q_head[u] = q_cnt++;
}
void solve(){
    init();
    cin >> n >> m >> s;
    for(int i = 0;i < n-1;i++){
        int u,v;cin >> u >> v;
        addEdge(u,v);
        addEdge(v,u);
    }
    for(int i = 0;i < m;i++){
        int a,b;cin >> a >> b;
        addEdge_q(a,b,i);
        addEdge_q(b,a,i);
    }
    tarjan(s);
    for(int i = 0;i < m;i++){
        cout<<ans[i]<<"\n";
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