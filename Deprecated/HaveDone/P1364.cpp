#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
struct Edge{
    int to;
    int next;
}edge[500];
int head[500];
int val[200];
int cnt;
int n;
void init(){
    cnt = 0;
    for(int i = 0;i < 500;i++){
        head[i] = -1;
        edge[i].next = -1;
    }
}
void addEdge(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
int dfs(int u,int dep,int f){
    int ans = 0;
    for(int i = head[u];i!=-1;i = edge[i].next){
        int v = edge[i].to;
        if(v!=f){
            ans += dfs(v,dep+1,u);
        }
    }
    return ans + dep*val[u];
}
void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        int w,l,r;cin >> w >> l >> r;
        val[i] = w;
        if(l!=0){
            addEdge(i,l);
            addEdge(l,i);
        }
        if(r!=0){
            addEdge(i,r);
            addEdge(r,i);
        }
    }
    int ans = inf;
    for(int i = 1;i <= n;i++){
        ans = min(ans,dfs(i,0,-1));
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1; //cin >> t;
    init();
    while(t--) solve();
    return 0;
}