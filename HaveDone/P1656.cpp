#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
    int to;
    int next;
}edge[10005];
struct Node{
    int u,v;
    bool operator <(const Node& a)const{
        return (u==a.u?v < a.v:u < a.u);
    }
};
int head[200];
int num[200],low[200];
int n,m,cnt,dfn;
vector<Node>ans;
void init(){
    cnt = dfn = 0;
    for(int i = 0;i < 200;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int u,int f){
    num[u] = low[u] = ++dfn;
    for(int i = head[u];~i;i = edge[i].next){
        int v = edge[i].to;
        if(!num[v]){
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] > num[u]){
                ans.push_back({min(u,v),min(u,v)});
            }
        }else if(num[v] < num[u] && v!=f){
            low[u] = min(low[u],low[v]);
        }
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
    dfs(1,-1);
    sort(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it.u<<" "<<it.v<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
}