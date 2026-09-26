#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double inf = 2e9;
struct node{
    int x;
    double dis;
    bool operator <(const node& a)const{
        return dis > a.dis;
    }
};
struct Edge{
    int to;
    int w;
    int next;
}edge[200005];
int head[2005];
int cnt;
void init(){
    cnt = 0;
    for(int i = 0;i < 2005;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v,int w){
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
inline int read(){
    int s = 0,f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch=='-') f = -f;
        ch = getchar();
    }
    while(isdigit(ch)){
        s = 10*s+ch-'0';
        ch = getchar();
    }
    return s*f;
}
void solve(){
    init();
    int n = read(),m = read();
    for(int i = 1;i <= m;i++){
        int u = read(),v = read(),w = read();
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    int a = read(),b = read();
    vector<double>dis(n+5,inf);
    vector<bool>done(n+5);
    priority_queue<node>q;
    q.push({b,100.0});
    while(!q.empty()){
        auto [u,d] = q.top();q.pop();
        if(done[u]) continue;
        done[u] = true;
        for(int i = head[u];~i;i = edge[i].next){
            int v = edge[i].to;
            int w = edge[i].w;
            if(done[v]) continue;
            if(d/(1.0 - 0.01*w) < dis[v]){
                dis[v] = d/(1.0 - 0.01*w);
                q.push({v,dis[v]});
            }
        }
    }
    printf("%.8lf",dis[a]);

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}