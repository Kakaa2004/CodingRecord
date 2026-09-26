#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
struct Edge{
    int to;
    int next;
}edge[N];
int head[20005];
int num[20005],low[20005],ans[20005];
int cnt;
int n,m;
int dfn = 0;
void init(){
    cnt = 0;
    for(int i = 0;i < 20005;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int u,int f){
    int child = 0;
    num[u] = low[u] = ++dfn;
    for(int i = head[u];~i;i = edge[i].next){
        int v = edge[i].to;
            if(!num[v]){
                child++;
                dfs(v,u);
                low[u] = min(low[u],low[v]);
                if(low[v] >= num[u] && u!=f){
                    ans[u] = 1;
                }
            }else if(num[v] < num[u] && v!=f){
                low[u] = min(low[u],num[v]);
            }
        
    }
    if(u==f && child >= 2){
        ans[u] = 1;
    }
}
void solve(){
    init();
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u,v;cin >> u >> v;
        addEdge(u,v);   
        addEdge(v,u);
    }
    for(int i = 1;i <= n;i++){
        if(!num[i]) dfs(i,i);
    }
    int sum = 0;
    for(int i = 1;i <= n;i++){
        if(ans[i]){
            sum++;
        }
    }
    cout<<sum<<"\n";
    for(int i = 1;i <= n;i++){
        if(ans[i]){
            cout<<i<<" ";
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}